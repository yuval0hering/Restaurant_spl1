#include "../../include/Action.h"

using namespace std;

BaseAction::BaseAction(): status(PENDING) {}

void BaseAction::act(Restaurant &restaurant) {

}

void BaseAction::complete() {
    status = COMPLETED;
}

void BaseAction::error(std::string errorMsg) {
    this->errorMsg = errorMsg;
    status = ERROR;
}

std::string BaseAction::getErrorMsg() const {
    return  errorMsg;
}

ActionStatus BaseAction::getStatus() const {
    return status;
}

BaseAction::~BaseAction(){};

