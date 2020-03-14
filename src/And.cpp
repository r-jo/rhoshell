#include "../header/And.h"

#include <iostream>
#include <string>

using namespace std;

class Base;
class Connector;

bool andConnector::execute(){
    if(left->execute() && right->execute()){return true;}
    else{return false;}
}
string andConnector::getCommand(){
    return  left->getCommand() + " && " +  right->getCommand();
}
