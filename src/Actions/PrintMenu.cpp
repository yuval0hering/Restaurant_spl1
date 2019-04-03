#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;

PrintMenu::PrintMenu() {}

void PrintMenu::act(Restaurant &restaurant) {

    this->complete();

    string str = "";

    for (unsigned int i = 0; i < restaurant.getMenu().size(); ++i) {
        if (restaurant.getMenu()[i].getType()==VEG){
            str += restaurant.getMenu()[i].getName() + " VEG " + to_string(restaurant.getMenu()[i].getPrice()) + "NIS\n";
        }
        else if (restaurant.getMenu()[i].getType()==SPC){
            str += restaurant.getMenu()[i].getName() + " SPC " + to_string(restaurant.getMenu()[i].getPrice()) + "NIS\n";
        }
        else if(restaurant.getMenu()[i].getType()==BVG){
            str += restaurant.getMenu()[i].getName() + " BVG " + to_string(restaurant.getMenu()[i].getPrice()) + "NIS\n";
        }
        else if(restaurant.getMenu()[i].getType()==ALC){
            str += restaurant.getMenu()[i].getName() + " ALC " + to_string(restaurant.getMenu()[i].getPrice()) + "NIS\n";
        }
    }
    cout <<str;
}

std::string PrintMenu::toString() const {
    return "menu Completed";
}

BaseAction* PrintMenu::Clone() {
    return new PrintMenu(*this);
}