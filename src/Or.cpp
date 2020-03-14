#include "../header/Or.h"

#include <iostream>

using namespace std;

class Base;
class Connector;

bool orConnector::execute(){
    if(left->execute() || right->execute()){return true;}
    else{return false;}
}
string orConnector::getCommand(){
    return left->getCommand() + " || " + right->getCommand();
}

