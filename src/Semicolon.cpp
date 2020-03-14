#include "../header/Semicolon.h"
#include "../header/Base.h"
#include "../header/Connector.h"

#include <iostream>

using namespace std;

class Base;
class Connector;

bool semiConnector::execute(){
  left->execute();
  if(right->execute()){return true;}
  else{return false;}
}

string semiConnector::getCommand(){
  return left->getCommand() + " ; " + right->getCommand();
}
