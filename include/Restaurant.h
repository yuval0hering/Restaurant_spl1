
#ifndef ASSIGNMENT_1_RESTAURANT_H
#define ASSIGNMENT_1_RESTAURANT_H

#include <vector>
#include <string>
#include "Dish.h"
#include "Table.h"
#include "Action.h"


class Restaurant{
public:
    Restaurant();//Ctor
    Restaurant(const std::string &configFilePath);//Ctor
    Restaurant(const Restaurant &other);//copy ctor
    Restaurant(Restaurant&& other);// move copy constructor
    virtual ~Restaurant();// destructor
    Restaurant & operator=(const Restaurant &other); //operator =
    Restaurant & operator=(Restaurant&& other);// move operator =

    void start();
    int getNumOfTables() const;
    Table* getTable(int ind);
    const std::vector<BaseAction*>& getActionsLog() const; // Returns a reference to the history of actions
    std::vector<Dish>& getMenu();

private:
    bool open;
    std::vector<Table*> tables;
    std::vector<Dish> menu;
    std::vector<BaseAction*> actionsLog;
    std :: vector <std::string> readFile(std::string path);
    void initiateTables(std::vector <std::string> lines, int numOfTables);
    void initiateMenu(std::vector <std::string> lines);
    int ParseCustomers(std::string input, std::vector<Customer*> &customers);
    int customerID;
    bool isBacked;
};

#endif //ASSIGNMENT_1_RESTAURANT_H
