#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;

PrintTableStatus::PrintTableStatus(int id):tableId(id) {}

void PrintTableStatus::act(Restaurant &restaurant) {
    table = restaurant.getTable(tableId);
    this->complete();

    string str = "";

    if(table->isOpen()){
        str += "Table " + to_string(tableId) + " status: open\n" + "Customers:\n";

        for (unsigned int i = 0; i < table->getCustomers().size(); ++i) {
            str += to_string(table->getCustomers()[i]->getId()) + " " + table->getCustomers()[i]->getName() +"\n";
        }
        str += "Orders:\n";
        for (unsigned int j = 0; j < table->getOrders().size(); ++j) {
            str += table->getOrders()[j].second.getName() + " " + to_string(table->getOrders()[j].second.getPrice())
                   + "NIS " + to_string(table->getOrders()[j].first) +"\n";
        }

        str += "Current Bill: " + to_string(table->getBill()) + "NIS\n";
    }
    else{
        str += "Table " + to_string(tableId) + " status: closed\n";
    }

    cout <<str;
}

std::string PrintTableStatus::toString() const {
    return "status " + to_string(tableId) + " Completed";
}

BaseAction* PrintTableStatus::Clone() {
    return new PrintTableStatus(*this);
}


