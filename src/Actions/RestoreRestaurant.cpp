#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;
extern Restaurant* backup;

RestoreResturant::RestoreResturant() {}

void RestoreResturant::act(Restaurant &restaurant) {
    if(backup != nullptr){
        restaurant = *backup;
        this->complete();
    }
    else{
        this->error("Error: No backup available");
        cout <<"Error: No backup available\n";
    }
}

std::string RestoreResturant::toString() const {
    string str =  "restore ";

    if(getStatus() == COMPLETED){
        str += "Completed";
    }
    else {
        str += this->getErrorMsg();
    }

    return str;
}


BaseAction* RestoreResturant::Clone() {
    return new RestoreResturant(*this);
}