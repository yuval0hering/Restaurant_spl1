#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;

CloseAll::CloseAll() {}

void CloseAll::act(Restaurant &restaurant) {
    string str = "";
    for (int i = 0; i < restaurant.getNumOfTables(); ++i) {
        if(restaurant.getTable(i)->isOpen()){
            str += "Table " + to_string(i) + " was closed. Bill " + to_string(restaurant.getTable(i)->getBill()) +"NIS\n";
            restaurant.getTable(i)->closeTable();
        }
    }
    this->complete();
    cout <<str;
}

std::string CloseAll::toString() const {
    return  "close all Completed";
}

BaseAction* CloseAll::Clone() {
    return new CloseAll(*this);
}