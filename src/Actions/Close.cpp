#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;


Close::Close(int id): tableId(id){}

void Close::act(Restaurant &restaurant) {


    if(tableId < restaurant.getNumOfTables() && restaurant.getTable(tableId)->isOpen()){
        int bill = restaurant.getTable(tableId)->getBill();
        restaurant.getTable(tableId)->closeTable();
        this->complete();

        //print:
        string str = "Table " + to_string(tableId) + " was closed. Bill " + to_string(bill) + "NIS\n";
        cout <<str;
    }
    else{
        this->error("Error: Table does not exist or is not open");
        cout <<"Error: Table does not exist or is not open\n";
    }
}

std::string Close::toString() const {
    string str = "close " + to_string(tableId)+ " ";

    if(getStatus() == COMPLETED){
        str += "Completed";
    }
    else {
        str += this->getErrorMsg();
    }

    return str;
}

BaseAction* Close::Clone() {
    return new Close(*this);
}

