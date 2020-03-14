#ifndef COMMAND_H
#define COMMAND_H

#include "Base.h"

#include <iostream>
#include <string>

using namespace std;

class Base;

class Command : public Base{
    public:
        string cmd;
    public:
        Command(string input){cmd = input;}
  //Execute function
         virtual bool execute();
  //Retrieve Commands
         string getCommand(){return cmd;}
};

#endif
