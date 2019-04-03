
#ifndef ASSIGNMENT_1_TABLE_H
#define ASSIGNMENT_1_TABLE_H

#include <vector>
#include "Customer.h"
#include "Dish.h"

typedef std::pair<int, Dish> OrderPair;

class Table{
public:
    Table(int t_capacity);
    Table(const Table &other);//copy ctor
    Table(Table&& other);// move copy constructor
    virtual ~Table();// destructor
    Table & operator=(const Table &other); //operator =
    Table & operator=(Table&& other);//move operator =


    int getCapacity() const;
    void addCustomer(Customer* customer);
    void removeCustomer(int id);
    Customer* getCustomer(int id);
    std::vector<Customer*>& getCustomers();
    std::vector<OrderPair>& getOrders();
    void order(const std::vector<Dish> &menu);
    void openTable();
    void closeTable();
    int getBill();
    bool isOpen();
private:
    int capacity;
    bool open;
    int bill;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList; //A list of pairs for each order in a table - (customer_id, Dish)
    Dish getDishByID(int id, const std::vector<Dish> &menu);
    bool Contains(int num, std::vector<int> vec);
};

#endif //ASSIGNMENT_1_TABLE_H
