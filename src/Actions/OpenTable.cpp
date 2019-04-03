#include "../../include/Action.h"
#include "../../include/Table.h"
#include "../../include/Restaurant.h"
#include "../../include/Customer.h"


using namespace std;

OpenTable::OpenTable(int id, std::vector<Customer *> &customersList): tableId(id), customers(customersList) {}



void OpenTable::act(Restaurant &restaurant) {

    if(tableId < restaurant.getNumOfTables()){
        Table *table = restaurant.getTable(tableId);

        if(!table->isOpen() && (int)customers.size() <= table->getCapacity()){
            table->openTable();
            for (unsigned int i = 0; i < customers.size(); ++i) {
                table->addCustomer(customers[i]->Clone());
            }

            this->complete();
        }
        else{
            this->error("Error: Table does not exist or is already open");
            cout <<"Error: Table does not exist or is already open\n";
        }
    }
    else{
        this->error("Error: Table does not exist or is already open");
        cout <<"Error: Table does not exist or is already open\n";
    }
}

std::string OpenTable::toString() const {

    string str = "open " + to_string(tableId);

    for (unsigned int i = 0; i < customers.size(); ++i) {
        str += " " + customers[i]->toString();
    }

    if(getStatus() == COMPLETED){
        str += " Completed";
    }
    else {
        str += " " + this->getErrorMsg();
    }
    return  str;
}

BaseAction* OpenTable::Clone() {
    return new OpenTable(*this);
}

void BaseAction::setStatus(ActionStatus status) {
 this->status = status;
}

void BaseAction::setErrorMsg(std::string errorMsg) {
    this->errorMsg = errorMsg;
}

///////RULE OF 3////////

OpenTable::OpenTable(const OpenTable &other): tableId(other.tableId){

    this->setErrorMsg(other.getErrorMsg());
    this->setStatus(other.getStatus());

    for (unsigned int i = 0; i < other.customers.size(); ++i) {
        customers.push_back(other.customers[i]->Clone());
    }
}

OpenTable::~OpenTable() {
    for (unsigned int i = 0; i < customers.size(); ++i) {
        delete(customers[i]);
    }
    customers.clear();
}
