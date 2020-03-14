#include "../header/Parser.h"
#include "../header/Connector.h"
#include "../header/Semicolon.h"
#include "../header/Or.h"
#include "../header/And.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

//Function stubs
void prompt();
/**
Function: main()
Parameters: none
Purpose: To initialize Rshell.
**/
int main(){
  while (1){
    //Initialize prompt
    prompt();
    //Accept user input
    string input;
    getline(cin, input);
    //If user input is "exit", break
    if(input == "exit" || input == "exit "){break;}
    //Else parse user input
    Parser* user = new Parser(input);
    user->parse();
  }
  return 0;
}
//Prompt Function
void prompt(){
  static int init = 1;
  if(init){
    write(STDOUT_FILENO, " \e[1;1H\e[2J",12);
    init = 0;
  }
  printf("rhoshell ~ ");
}
