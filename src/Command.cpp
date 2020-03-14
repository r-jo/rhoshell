#include "../header/Command.h"
#include "../header/Parser.h"
#include "../header/Base.h"

#include <iostream>
#include <sstream>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Parser;
class Command;
class Connector;
class Base;
/**
Funtion: execute();
Parameters: None
**/
bool Command::execute(){
  if (cmd == "exit" || cmd == "exit "){
    exit(2);
    return false;
  }
  //Vector to store chars parsed
  vector<char *> parsed;
  char *truncStr = strtok((char * ) this->cmd.c_str(), " ");
  while (truncStr != NULL) {
    parsed.push_back(truncStr);
    //Searches for the next token
    truncStr = strtok(NULL, " ");
  }
  //Creates an array of chars for args
  char **args = new char *[parsed.size() + 1];
  for (int i = 0; i < parsed.size(); i++){args[i] = parsed[i];}
  args[parsed.size()] = NULL;
  if (fork() == 0){
    if (execvp (args[0],args) == -1) {
      perror("exec");
      return false;
    }
  }
  else {wait(NULL);}
  return true;
}
