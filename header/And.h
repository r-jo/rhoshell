#ifndef __AND_H__
#define __AND_H__

#include "Connector.h"
#include "Base.h"

using namespace std;

class Base;

class andConnector : public Connector{
    public:
        andConnector(Base *left, Base *right) : Connector(left, right){} 
        virtual bool execute();
        virtual string getCommand();
};

#endif

