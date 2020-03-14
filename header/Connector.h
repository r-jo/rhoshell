#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "Base.h"
#include "Command.h"

using namespace std;

class Base;

class Connector: public Base{
protected:
  Base* left;
  Base* right;
public:
  Connector(){}
  Connector(Base* l, Base* r){
    left = l;
    right = r;
  }
  virtual bool execute() = 0;
  virtual string getCommand() = 0;
};

#endif
