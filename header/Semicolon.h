#ifndef __SEMICOLON_H__
#define __SEMICOLON_H__

#include "Connector.h"
#include "Base.h"

using namespace std;

class Base;

class semiConnector : public Connector{
    public:
        semiConnector(Base *left, Base *right) : Connector(left, right){} 
        virtual bool execute();
        virtual string  getCommand();
};

#endif
