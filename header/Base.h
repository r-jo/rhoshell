#ifndef __BASE_H__
#define __BASE_H__

#include <string>
#include <iostream>

using namespace std;

class Base {
    public:
        virtual bool execute() = 0;
        virtual string getCommand() = 0;
};

#endif
