#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "Command.h"
#include "Base.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

using namespace std;

class Base;
class Command;

class TestCommand : public Command {
    public:
        TestCommand(string input) : Command(input){};
        virtual bool execute();
        virtual string getCommand();
};

#endif
