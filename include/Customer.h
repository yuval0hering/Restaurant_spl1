
#ifndef ASSIGNMENT_1_CUSTOMER_H
#define ASSIGNMENT_1_CUSTOMER_H

#include <vector>
#include <string>
#include "Dish.h"

class Customer{
public:
    Customer(std::string c_name, int c_id);// Ctor
    virtual ~Customer()=0;// destructor
    virtual Customer* Clone()=0;

    virtual std::vector<int> order(const std::vector<Dish> &menu)=0;
    virtual std::string toString() const = 0;
    std::string getName() const;
    int getId() const;


private:
    const std::string name;
    const int id;

};


class VegetarianCustomer : public Customer {
public:
    VegetarianCustomer(std::string name, int id);//Ctor
    Customer* Clone();
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
};


class CheapCustomer : public Customer {
public:
    CheapCustomer(std::string name, int id);
    Customer* Clone();
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
    bool getIsOrdered();
private:
    bool isOrederd;
};


class SpicyCustomer : public Customer {
public:
    SpicyCustomer(std::string name, int id);
    Customer* Clone();
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;
private:
    bool isOrdered;
};


class AlchoholicCustomer : public Customer {
public:
    AlchoholicCustomer(std::string name, int id);
    Customer* Clone();
    std::vector<int> order(const std::vector<Dish> &menu);
    std::string toString() const;

private:
    int lastID;
    int lastPrice;
    int nextDishID(const std::vector<Dish> &menu);
    int nextDishIDPrice(const std::vector<Dish> &menu);
};

#endif //ASSIGNMENT_1_CUSTOMER_H
