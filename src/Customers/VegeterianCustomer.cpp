#include "../../include/Customer.h"

VegetarianCustomer::VegetarianCustomer(std::string name, int id):Customer(name,id) {}

std::vector<int> VegetarianCustomer::order(const std::vector<Dish> &menu) {
    std::vector<int> vegOrder(2);//first place - food, second place - drink
    int maxPrice = -1;
    int minID = -1;
    for (unsigned int i = 0; i < menu.size(); ++i) {
        if(menu[i].getType() == VEG){
            if(minID == -1 || menu[i].getId() < minID){
                minID = menu[i].getId();
                vegOrder[0] = minID;
            }
        }

        if(menu[i].getType() == BVG){
            if(menu[i].getPrice() > maxPrice || (menu[i].getPrice() == maxPrice && menu[i].getId() < vegOrder[1])){
                maxPrice = menu[i].getPrice();
                vegOrder[1] = menu[i].getId();
            }

        }
    }

    return vegOrder;
}

std::string VegetarianCustomer::toString() const {
    return this->getName() + ",veg";
}

Customer* VegetarianCustomer::Clone(){
    return new VegetarianCustomer(*this);
}

