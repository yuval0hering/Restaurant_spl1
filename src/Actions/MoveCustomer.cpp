#include "../../include/Action.h"
#include "../../include/Restaurant.h"
#include "../../include/Customer.h"
#include "../../include/Table.h"

using namespace std;

MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTable(src), dstTable(dst), id(customerId) {}

void MoveCustomer::act(Restaurant &restaurant) {

    if(srcTable < restaurant.getNumOfTables() && dstTable < restaurant.getNumOfTables()){
        Table *originTable = restaurant.getTable(srcTable);
        Table *targetTable = restaurant.getTable(dstTable);

        if(originTable->isOpen() && targetTable->isOpen() && originTable->getCustomer(id)!= nullptr && targetTable->getCapacity() > (int)targetTable->getCustomers().size() ){

            Customer *newCustomer = originTable->getCustomer(id);
            originTable->removeCustomer(id);
            targetTable->addCustomer(newCustomer);
            MoveOrders(newCustomer, originTable,targetTable);

            if(originTable->getCustomers().empty()){
                originTable->closeTable();
            }
            this->complete();
        }
        else{
            this->error("Error: Cannot move customer");
            cout <<"Error: Cannot move customer\n";
        }
    }
    else{
        this->error("Error: Cannot move customer");
        cout <<"Error: Cannot move customer\n";
    }
}

std::string MoveCustomer::toString() const {
    string str =  "move " + to_string(srcTable) + " " + to_string(dstTable) + " " + to_string(id)+ " ";

    if(getStatus() == COMPLETED){
        str += "Completed";
    }
    else {
        str += this->getErrorMsg();
    }

    return str;
}



void MoveCustomer:: MoveOrders(Customer *customer, Table *src, Table *dst){
    //remove the orders of customer from src and add the orders to dst
    vector <OrderPair> *srcOrders = &src->getOrders();
    vector <OrderPair> *dstOrders = &dst->getOrders();
    vector <OrderPair> newSrcOrders;

    for (unsigned int i = 0; i < srcOrders->size(); ++i) {
        if(srcOrders->at(i).first == customer->getId()){
            OrderPair pair(srcOrders->at(i).first, srcOrders->at(i).second);
            dstOrders->push_back(pair);
        }
        else{
            newSrcOrders.push_back(srcOrders->at(i));
        }
    }
    srcOrders->clear();
    for (unsigned int j = 0; j < newSrcOrders.size(); ++j) {
        srcOrders->push_back(newSrcOrders[j]);
    }
}

BaseAction* MoveCustomer::Clone() {
    return new MoveCustomer(*this);
}