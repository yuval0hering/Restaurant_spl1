#include "../include/Restaurant.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


Restaurant::Restaurant():open(false), customerID(0), isBacked(false){}

Restaurant::Restaurant(const string &configFilePath):open(false),customerID(0), isBacked(false) {

    vector <string> lines = readFile(configFilePath);

    string::size_type sz;

    int numOfTables = stoi(lines[0], &sz);
    initiateTables(lines, numOfTables);

    initiateMenu(lines);
}

const std::vector<BaseAction*>& Restaurant::getActionsLog() const {
    return this->actionsLog;
}

std::vector<Dish>& Restaurant::getMenu() {
    return menu;
}

int Restaurant::getNumOfTables() const {
    return (int)tables.size();
}

void Restaurant::start() {
    cout <<"Restaurant is now open!"<<endl;
    open = true;
    string input = "";
    getline(cin,input);
    bool isBacked= false;

    string::size_type sz;


    while (input != "closeall"){
        int tableID;
        string temp4=input.substr(0,4);
        string temp5=input.substr(0,5);
        string temp6=input.substr(0,6);

        if(temp4 == "open"){
            vector <Customer*> customers;
            tableID = ParseCustomers(input,customers);
            BaseAction *openTable = new OpenTable(tableID, customers);
            openTable->act(*this);
            actionsLog.push_back(openTable);
        }
        else if(temp5 == "order"){
            tableID = stoi(input.substr(6,input.size() - 6), &sz);
            BaseAction *order = new Order(tableID);
            order->act(*this);
            actionsLog.push_back(order);
        }
        else if(temp4 == "move"){

            string token;
            istringstream is(input);

            getline(is,token,' ');//move

            getline(is,token,' ');//src table id
            int srcID = stoi(token, &sz);

            getline(is,token,' ');//dst table id
            int dstID = stoi(token, &sz);

            getline(is,token,' ');//customer table id
            int customerID = stoi(token, &sz);

            BaseAction *moveCustomer = new MoveCustomer(srcID, dstID, customerID);
            moveCustomer->act(*this);
            actionsLog.push_back(moveCustomer);
        }
        else if(temp5 == "close") {
            tableID = stoi(input.substr(6, input.size() - 6), &sz);
            BaseAction *close = new Close(tableID);
            close->act(*this);
            actionsLog.push_back(close);
            }
        else if(input == "menu") {
            BaseAction *printMenu = new PrintMenu();
            printMenu->act(*this);
            actionsLog.push_back(printMenu);
        }
        else if(temp6 == "status"){
            tableID = stoi(input.substr(7,input.size() - 7), &sz);
            BaseAction *printTableStatus = new PrintTableStatus(tableID);
            printTableStatus->act(*this);
            actionsLog.push_back(printTableStatus);
        }
        else if(input == "log") {
            BaseAction *printActionsLog = new PrintActionsLog();
            printActionsLog->act(*this);
            actionsLog.push_back(printActionsLog);
        }
        else if(input == "backup") {
            BaseAction *backupRestaurant = new BackupRestaurant(isBacked);
            backupRestaurant->act(*this);
            actionsLog.push_back(backupRestaurant);
            isBacked = true;
        }
        else if(input == "restore") {
            BaseAction *restoreRestaurant = new RestoreResturant();
            restoreRestaurant->act(*this);
            actionsLog.push_back(restoreRestaurant);
        }

        getline(cin,input);
    }

        BaseAction *closeall = new CloseAll();
        closeall->act(*this);
        actionsLog.push_back(closeall);
        this->open = false;
}

Table* Restaurant::getTable(int ind) {
    if(ind<(int)tables.size()){
        return tables[ind];
    }
    else return nullptr;
}

vector <string> Restaurant::readFile(string path){
    vector <string> lines;
    ifstream input;
    string line;
    input.open(path);

    //read the file to the vector lines, ignore empty lines and comments
    while (getline(input, line)) {
        if (line.length() != 0 && line[0] != '#') {
            lines.push_back(line);
        }
    }
    input.close();
        return lines;
}

void Restaurant::initiateTables(vector <string> lines, int numOfTables){
    //initiate the Tables vector by the input file
    string token;
    string::size_type sz;
    istringstream is(lines[1]);

    for (int i = 0; i < numOfTables; i++) {
        getline(is,token,',');
        int capacity = stoi(token, &sz);
        tables.push_back(new Table(capacity));
    }
}
void Restaurant::initiateMenu(vector <string> lines){
    //initiate the dishes in the menu by the input file
    string token;
    string::size_type sz;

    for (unsigned int j = 2; j < lines.size(); ++j) {
        istringstream is(lines[j]);
        vector <string> dish;
        for (unsigned int i = 0; i < 3; ++i) {
            getline(is,token,',');
            dish.push_back(token);
        }
        int dishPrice = stoi(dish[2], &sz);
        DishType type = VEG;

        if(dish[1] == "VEG") type = VEG;
        else if(dish[1] == "SPC") type = SPC;
        else if(dish[1] == "BVG") type = BVG;
        else if(dish[1] == "ALC") type = ALC;

        menu.emplace_back(Dish(j-2,dish[0],dishPrice, type));
    }
}

//parse the input to table id and list of customers
int Restaurant:: ParseCustomers(string input, vector<Customer*> &customers){
    int tableID;
    string token;
    string::size_type sz;
    istringstream is(input);

    getline(is,token,' ');//open
    getline(is,token,' ');//table id
    tableID = stoi(token, &sz);

    while(getline(is,token,' ')){
        string customerToken(token);
        istringstream isCustomer(customerToken);

        getline(isCustomer,customerToken,',');//name
        string name(customerToken);

        getline(isCustomer,customerToken,',');//strategy
        string strategy(customerToken);

        Customer *customer = nullptr;
        if(strategy == "veg"){
            customer = new VegetarianCustomer(name,customerID);
        }
        else if(strategy == "spc"){
            customer = new SpicyCustomer(name,customerID);
        }
        else if(strategy == "chp"){
            customer = new CheapCustomer(name,customerID);
        }
        else if(strategy == "alc"){
            customer = new AlchoholicCustomer(name,customerID);
        }
        customerID++;
        customers.push_back(customer);
    }

    return tableID;

}



///////RULE OF 5////////

//Copy Ctor:
Restaurant::Restaurant(const Restaurant &other): open(other.open), customerID(other.customerID) {
    for (unsigned int i = 0; i < other.menu.size(); ++i) {
        this->menu.push_back(other.menu[i]);
    }
    for (unsigned int j = 0; j < other.tables.size(); ++j) {
        this->tables.push_back(new Table(*other.tables[j]));
    }
    for (unsigned int k = 0; k < other.actionsLog.size(); ++k) {
        this->actionsLog.push_back(other.actionsLog[k]->Clone());
    }
}

//Destractor:
Restaurant::~Restaurant() {
    for (unsigned int i = 0; i < this->tables.size(); ++i) {
        delete(tables[i]);
    }
    this->tables.clear();
    for (unsigned int j = 0; j < this->actionsLog.size() ; ++j) {
        delete(actionsLog[j]);
    }
    this->actionsLog.clear();
}

//Operator =:
Restaurant &Restaurant::operator=(const Restaurant &other) {
    if(this!=&other){
        this->customerID = other.customerID;
        this->open = other.open;
        for (unsigned int i = 0; i <this->tables.size(); ++i) {//delete the tables
                delete(tables[i]);
        }
        this->tables.clear(); //delete the pointers to the tables
        for (unsigned int j = 0; j < other.tables.size(); ++j) { //copy the tables from other
            this->tables.push_back(new Table(*other.tables[j]));
        }

        for (unsigned int k = 0; k < this->actionsLog.size(); ++k) { //delete the actions from the actionsLog
            delete(actionsLog[k]);
        }

        this->actionsLog.clear(); //delete the pointers of the actions
        for (unsigned int l = 0; l < other.actionsLog.size(); ++l) {// copy the actions from other
            this->actionsLog.push_back(other.actionsLog[l]->Clone());
        }
    }
    return (*this);
}

//move copy Ctor
Restaurant::Restaurant(Restaurant &&other):open(other.open),
tables(other.tables), actionsLog(other.actionsLog){



    customerID = other.customerID;
    for (unsigned int i = 0; i < other.menu.size(); ++i) {
        menu.push_back(other.menu[i]);
    }

    other.menu.clear();
    other.tables.clear();
    other.actionsLog.clear();

}

//move operator =:
Restaurant &Restaurant::operator=(Restaurant &&other){
    if(this!=&other){
        this->customerID=other.customerID;
        this->open=other.open;
        this->menu.clear(); //deletes the dishes from the menu
        for (unsigned int m = 0; m < other.menu.size(); ++m) {
            this->menu.push_back(other.menu[m]);
        }
        other.menu.clear();

        for (unsigned int i = 0; i <this->tables.size(); ++i) {//delete the tables
            delete(tables[i]);
        }
        this->tables.clear(); //delete the pointers to the tables
        this->tables=other.tables;
        other.tables.clear();

        for (unsigned int k = 0; k < this->actionsLog.size(); ++k) { //delete the actions from the actionsLog
            delete(actionsLog[k]);
        }
        this->actionsLog.clear(); //delete the pointers of the actions
        this->actionsLog=other.actionsLog;
        other.actionsLog.clear();
    }
    return (*this);
}




