
#ifndef ASSIGNMENT_1_ACTION_H
#define ASSIGNMENT_1_ACTION_H

#include <string>
#include <iostream>
#include "Customer.h"
#include "Table.h"

enum ActionStatus{
    PENDING, COMPLETED, ERROR
};

//Forward declaration
class Restaurant;

class BaseAction{
public:
    BaseAction(); //Ctor
    virtual ~BaseAction()=0;// destructor
    virtual BaseAction* Clone()=0;
    ActionStatus getStatus() const;
    virtual void act(Restaurant& restaurant)=0;
    virtual std::string toString() const=0;
    void setStatus(ActionStatus status);
    void setErrorMsg(std::string errorMsg);

protected:
    void complete();
    void error(std::string errorMsg);
    std::string getErrorMsg() const;
private:
    std::string errorMsg;
    ActionStatus status;
};


class OpenTable : public BaseAction {
public:
    OpenTable(int id, std::vector<Customer *> &customersList);
    OpenTable(const OpenTable &other);//copy ctor
    virtual ~OpenTable();// destructor
    OpenTable & operator=(const OpenTable &other); //operator =
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;


private:
    const int tableId;
    std::vector<Customer *> customers;
};


class Order : public BaseAction {
public:
    Order(int id);
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;

private:
    const int tableId;
    Table *table;
    std::string getCustomerNameByID(int id) const;
};


class MoveCustomer : public BaseAction {
public:
    MoveCustomer(int src, int dst, int customerId);
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;

private:
    const int srcTable;
    const int dstTable;
    const int id;
    void MoveOrders(Customer *customer, Table *src, Table *dst);
};


class Close : public BaseAction {
public:
    Close(int id);
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;

private:
    const int tableId;
};


class CloseAll : public BaseAction {
public:
    CloseAll();
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;

private:
};


class PrintMenu : public BaseAction {
public:
    PrintMenu();
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;

private:
};


class PrintTableStatus : public BaseAction {
public:
    PrintTableStatus(int id);
    void act(Restaurant &restaurant);
    std::string toString() const;
    BaseAction* Clone();
private:
    const int tableId;
    Table *table;
};


class PrintActionsLog : public BaseAction {
public:
    PrintActionsLog();
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;

private:
    std::vector<BaseAction*> actions;
};


class BackupRestaurant : public BaseAction {
public:
    BackupRestaurant();
    BackupRestaurant(bool isBacked);
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;

private:
    bool isBacked;
};


class RestoreResturant : public BaseAction {
public:
    RestoreResturant();
    BaseAction* Clone();
    void act(Restaurant &restaurant);
    std::string toString() const;


};

#endif //ASSIGNMENT_1_ACTION_H
