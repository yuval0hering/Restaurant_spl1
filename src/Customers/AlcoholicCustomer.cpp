#include "../../include/Customer.h"

AlchoholicCustomer::AlchoholicCustomer(std::string name, int id):Customer(name,id) {
    lastID = -1;
    lastPrice = -1;
}

std::vector<int> AlchoholicCustomer::order(const std::vector<Dish> &menu) {
    //return the next ALC dish by price order, return -1 if there isnt next ALC dish
    std::vector<int> alcoholicOrder(1);
    alcoholicOrder[0] = -1;
    int nextID = nextDishID(menu);
    if(nextID != -1){
        alcoholicOrder[0] = nextID;
        lastID = nextID;
    }
    else{
        int nextPriceID = nextDishIDPrice(menu);
        if(nextPriceID != -1){
            alcoholicOrder[0] = nextPriceID;
            lastID = nextPriceID;
        }
    }
    return alcoholicOrder;
}

std::string AlchoholicCustomer::toString() const {
    return this->getName() + ",alc";
}

int AlchoholicCustomer::nextDishID(const std::vector<Dish> &menu) {
    //find the next ALC dish with the same price and bigger id, return -1 if there isnt bidder id with the same price
    int nextID = -1;
    for (unsigned int i = 0; i <menu.size() ; ++i) {
        if(menu[i].getPrice() == lastPrice && menu[i].getType() == ALC){
            if((menu[i].getId() > lastID && nextID == -1) || (menu[i].getId() > lastID && menu[i].getId() < nextID)){
                nextID = menu[i].getId();
            }
        }
    }
    return nextID;
}

int AlchoholicCustomer::nextDishIDPrice(const std::vector<Dish> &menu) {
    //find the next bigger ALC Price with the smallest ID, return -1 if there isn`t price bigger then the last price
    int nextPrice = -1;
    int minID = -1;
    for (unsigned int i = 0; i <menu.size(); ++i) { // find the next price with the lowest id
        if(menu[i].getPrice() > lastPrice && (menu[i].getPrice()<=nextPrice || nextPrice == -1) && menu[i].getType() == ALC){
            if((menu[i].getId() < minID && menu[i].getPrice() == nextPrice) || (menu[i].getPrice()<nextPrice || nextPrice == -1)){
                minID = menu[i].getId();
                nextPrice = menu[i].getPrice();
            }
        }
    }
    if(nextPrice != -1){
        lastPrice = nextPrice;
    }
    return  minID;
}

Customer* AlchoholicCustomer::Clone(){
    return new AlchoholicCustomer(*this);
}