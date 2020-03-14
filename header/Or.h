#ifndef __OR_H__
#define __OR_H__

#include "Connector.h"
#include "Base.h"

using namespace std;

class Base;

class orConnector : public Connector{
    public:
        orConnector(Base *left, Base *right) : Connector(left, right){} 
        virtual bool execute();
        virtual string getCommand();
};

#endif

