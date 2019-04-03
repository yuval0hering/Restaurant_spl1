#include "../../include/Customer.h"

CheapCustomer::CheapCustomer(std::string name, int id):Customer(name,id) {
    isOrederd = false;
}

std::vector<int> CheapCustomer::order(const std::vector<Dish> &menu) {
    //return the id of the dish in the menu or -1 if the customer already order
    std::vector<int> cheapOrder(1);
    cheapOrder[0] = -1;
    int minPrice = -1;

    if(!isOrederd){
        for (unsigned int i = 0; i < menu.size(); ++i) {
            if(minPrice == -1 || menu[i].getPrice() < minPrice || (menu[i].getPrice() == minPrice && menu[i].getId() < cheapOrder[0])){
                cheapOrder[0] = menu[i].getId();
                minPrice = menu[i].getPrice();
                isOrederd = true;
            }
        }
    }
    return cheapOrder;

}

std::string CheapCustomer::toString() const {
    return this->getName() + ",chp";
}

bool CheapCustomer::getIsOrdered() {
    return isOrederd;
}

Customer* CheapCustomer::Clone(){
    return new CheapCustomer(*this);
}


