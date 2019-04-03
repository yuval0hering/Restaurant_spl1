#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;

Order::Order(int id): tableId(id){}

void Order::act(Restaurant &restaurant) {

    if(tableId < restaurant.getNumOfTables() && restaurant.getTable(tableId)->isOpen()){
        table = restaurant.getTable(tableId);
        int orderSize = (int)table->getOrders().size();
        table->order(restaurant.getMenu());
        this->complete();

        //print:
        string str;
        for (unsigned int i = orderSize; i < table->getOrders().size(); ++i) {
            str = str + this->getCustomerNameByID(table->getOrders()[i].first) + " ordered " + table->getOrders()[i].second.getName() + "\n";
        }
        cout << str;
    }
    else
    {
        this->error("Error: Table does not exist or is not open");
        cout <<"Error: Table does not exist or is not open\n";
    }

}

std::string Order::toString() const {
    string str = "order " + to_string(tableId) + " ";

    if(getStatus() == COMPLETED){
        str += "Completed";
    }
    else {
        str += this->getErrorMsg();
    }
    return str;
}

std::string Order:: getCustomerNameByID(int id) const{
    for (unsigned int i = 0; i < table->getCustomers().size(); ++i) {
        if(table->getCustomers()[i]->getId() == id){
            return table->getCustomers()[i]->getName();
        }
    }
    return nullptr;
}

BaseAction* Order::Clone() {
    return new Order(*this);
}

