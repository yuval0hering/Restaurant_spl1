#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;
extern Restaurant* backup;

BackupRestaurant::BackupRestaurant() : isBacked(false){}

BackupRestaurant::BackupRestaurant(bool isBacked):isBacked(isBacked) {}

void BackupRestaurant::act(Restaurant &restaurant) {

    if(!isBacked){
        backup = new Restaurant(restaurant);
        isBacked = true;
    }
    else{
        *backup = restaurant;
    }
    this->complete();

}

std::string BackupRestaurant::toString() const {
    return "backup Completed";
}

BaseAction *BackupRestaurant::Clone() {
    return new BackupRestaurant(*this);
}


