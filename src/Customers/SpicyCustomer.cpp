#include "../../include/Customer.h"

SpicyCustomer::SpicyCustomer(std::string name, int id):Customer(name,id),isOrdered(false){}

std::vector<int> SpicyCustomer::order(const std::vector<Dish> &menu) {
    std::vector<int> spicyOrder(1);//first place - food, second place - drink
    int maxSpicyPrice = -1;
    int minNonAlcPrice = -1;

    for (unsigned int i = 0; i < menu.size() && isOrdered; ++i) {
        if (menu.at(i).getType() == BVG) {
            if (minNonAlcPrice == -1 || menu.at(i).getPrice() < minNonAlcPrice ||
                (menu.at(i).getPrice() < minNonAlcPrice && menu[i].getId() < spicyOrder[0])) {
                minNonAlcPrice = menu.at(i).getPrice();
                spicyOrder[0] = menu[i].getId();
            }
        }
    }

    if(!isOrdered){
        for (unsigned int i = 0; i < menu.size(); ++i) {
            if (menu.at(i).getType() == SPC) {
                if (menu.at(i).getPrice() > maxSpicyPrice ||
                    (menu.at(i).getPrice() == maxSpicyPrice && menu[i].getId() < spicyOrder[0])) {
                    maxSpicyPrice = menu.at(i).getPrice();
                    spicyOrder[0] = menu.at(i).getId();
                    isOrdered = true;
                }
            }
        }
    }

    return spicyOrder;
}

std::string SpicyCustomer::toString() const {
    return this->getName() + ",spc";
}

Customer* SpicyCustomer::Clone(){
    return new SpicyCustomer(*this);
}