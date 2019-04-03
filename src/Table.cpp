#include "../include/Table.h"

using namespace std;

Table::Table(int t_capacity):capacity(t_capacity),open(false),bill(0){}

void Table::addCustomer(Customer *customer) {
    customersList.push_back(customer);
}

void Table::closeTable() {
    open = false;

    for (unsigned int i = 0; i < customersList.size(); ++i) {
        delete(customersList[i]);
    }

    customersList.clear();
    orderList.clear();
    bill = 0;
}

int Table::getCapacity() const {
    return capacity;
}

Customer* Table::getCustomer(int id) {
    for (unsigned int i = 0; i < customersList.size(); ++i) {
        if(customersList[i]->getId() == id)
            return customersList[i];
    }
    return nullptr;
}

std::vector<Customer*>& Table::getCustomers() {
    return  customersList;
}

std::vector<OrderPair>& Table::getOrders() {
    return orderList;
}

bool Table::isOpen() {
    return open;
}

void Table::openTable() {
    open = true;
}

void Table::removeCustomer(int id) {
    for (unsigned int i = 0; i < customersList.size(); ++i) {
        if(customersList[i]->getId() == id)
            customersList.erase(customersList.begin() + i);
    }
}

int Table::getBill() {
    bill = 0;
    for (unsigned int i = 0; i < orderList.size(); ++i) {
        bill += orderList[i].second.getPrice();
    }
    return bill;
}

void Table::order(const std::vector<Dish> &menu) {

    for (unsigned int i = 0; i < customersList.size(); ++i) {
        vector <int> customerOrder = customersList[i]->order(menu);
        if(!(Contains(-1, customerOrder))){ //if the customer order success
            for (unsigned int j = 0; j < customerOrder.size(); ++j) {
                OrderPair pair(customersList[i]->getId(), getDishByID(customerOrder[j],menu));
                orderList.push_back(pair);
            }
        }
    }
}

Dish Table::getDishByID(int id, const std::vector<Dish> &menu) {
    //return the dish with the accepted id
    for (unsigned int i = 0; i < menu.size(); ++i) {
        if(menu[i].getId() == id)
            return menu[i];
    }
    return Dish(-1, "", -1, VEG);
}

bool Table::Contains(int num, vector<int> vec){
    for (unsigned int i = 0; i < vec.size(); ++i) {
        if(vec[i] == num)
            return true;
    }
    return false;
}

///////RULE OF 5////////

//Copy Ctor:
Table::Table(const Table &other):capacity(other.getCapacity()), open(other.open), bill(other.bill)  {

    for (unsigned int i = 0; i < other.orderList.size(); ++i) {
        this->orderList.push_back(other.orderList[i]);
    }
    for (unsigned int i = 0; i < other.customersList.size(); ++i) {
        customersList.push_back(other.customersList[i]->Clone());
    }
}
//Move Copy Ctor =:
Table::Table(Table &&other):capacity(other.getCapacity()), open(other.open), bill(other.bill){

    for (unsigned int i = 0; i < other.getOrders().size(); ++i) {
        this->orderList.push_back(other.getOrders()[i]);
    }

    for (unsigned int j = 0; j < other.getCustomers().size(); ++j) {
        this->customersList.push_back(other.customersList[j]);
    }
    other.orderList.clear();
    other.customersList.clear();

}

//Destructor:
Table::~Table() {
    for (unsigned int i = 0; i < this->customersList.size(); ++i) {
       delete(customersList[i]);
    }
}

//Operator =:
Table & Table::operator=(const Table &other) {
    if (this!=&other){

        this->capacity=other.capacity;
        this->open=other.open;
        this->bill=other.bill;
        this->orderList.clear();
        for (unsigned int i = 0; i < other.orderList.size(); ++i) {
            this->orderList.push_back(other.orderList[i]);
        }
        for (unsigned int k = 0; k < this->customersList.size(); ++k) {
            delete(this->customersList[k]);
        }
        this->customersList.clear();
        for (unsigned int j = 0; j < other.customersList.size(); ++j) {
            this->customersList.push_back(other.customersList[j]->Clone());
        }

    }
    return *this;

}

//Move Operator =:
Table &Table::operator=(Table &&other) {
    if (this!=&other){

        this->capacity=other.capacity;
        this->open=other.open;
        this->bill=other.bill;
        this->orderList.clear();
        for (unsigned int i = 0; i < other.orderList.size(); ++i) {
            this->orderList.push_back(other.orderList[i]);
        }
        other.orderList.clear();
        for (unsigned int k = 0; k < this->customersList.size(); ++k) {
            delete(this->customersList[k]);
        }
        this->customersList.clear();
        this->customersList=other.customersList;
//        for (int j = 0; j < other.customersList.size(); ++j) {
//            this->customersList.push_back(other.customersList[j]->Clone());
//        }
        other.customersList.clear();
    }

    return *this;
}







