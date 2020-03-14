#ifndef PARSER_H
#define PARSER_H

#include "Base.h"
#include "Command.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Base;
class Command;

class Parser{
protected:
  Base *root;
  string cmd;
  vector <string> argV;

public:
  //Default contructor
  Parser(){root = 0;}
  Parser(Base * root){this->root = root;}
  Parser(string& input){cmd = input;}
  //parsing function
  void parse();
};

#endif
