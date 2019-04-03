#include "../../include/Action.h"
#include "../../include/Restaurant.h"

using namespace std;

PrintActionsLog::PrintActionsLog() {}


void PrintActionsLog::act(Restaurant &restaurant) {
    actions = restaurant.getActionsLog();
    this->complete();

    string str;

    for (unsigned int i = 0; i < actions.size(); ++i) {
        str += actions[i]->toString() + "\n";
    }

    cout <<str;
}

std::string PrintActionsLog::toString() const {
    return "log Completed";
}

BaseAction* PrintActionsLog::Clone() {
    return new PrintActionsLog(*this);
}