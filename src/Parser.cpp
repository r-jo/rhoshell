#include "../header/Base.h"
#include "../header/Command.h"
#include "../header/Connector.h"
#include "../header/Parser.h"
#include "../header/Semicolon.h"
#include "../header/And.h"
#include "../header/Or.h"
#include "../header/TestCommand.h"

#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Base;

/**
* Name: parse()
* Parameters: None
* Function: Accepts user input and executes command based on parsing
**/
void Parser::parse(){
  stack<Base*> parsingTree;
  queue<string> parenthesesTree;
  root = new Command("");

  //Condition to check '#' symbol
  //If '#' is found, then ignore all characters after '#'
  if(cmd.find('#') != -1){
    int pound = cmd.find('#');
    string substrCmd = cmd.substr(0, pound);
    Base* cmdPound = new Command(substrCmd);
    parsingTree.push(cmdPound);
  }

  //Condition to check for brackets and parentheses
  if (cmd.at(0) == '[' || cmd.substr(0,4) == "test"){
    root = new TestCommand(cmd);
  }else{
    if ((cmd.find('(') != -1) && (cmd.find(')') != -1)){
      while ((cmd.find('(') != -1) && (cmd.find(')') != -1)){
        int charOne = cmd.find('(') + 1;
        int charTwo = cmd.find(')') - 1;
        string bounded = cmd.substr(charOne, charTwo - charOne + 1);
        parenthesesTree.push(bounded);
        cmd = cmd.substr(0,cmd.find('(')) + cmd.substr(cmd.find(')'), cmd.size() - cmd.find(')') - 1);
      }
      while (!parenthesesTree.empty()){
        Parser* temp = new Parser(parenthesesTree.front());
        temp->parse();
        parenthesesTree.pop();
      }
      if (cmd == ""){return;}
  }
  if (cmd.size() > 2) {
    if (cmd.at(0) == ')'){
      if (cmd.at(1) == '&' || cmd.at(1) == '|'){cmd = cmd.substr(4);
      }else if(cmd.at(1) == ';'){cmd = cmd.substr(2);}
    }
    if(cmd.at(cmd.size() - 2) == ';' ){
      cmd = cmd.substr(0, cmd.size() - 2);
    }else if (cmd.at(cmd.size() - 3) == '|' || cmd.at(cmd.size() - 3) == '&' ){
      cmd = cmd.substr(0, cmd.size() - 4);
    }
  }

  //Condition to check for ' ' symbol
  //If ' ' is found then create firstCommand new command and push onto stack
  if(cmd.find(' ') == -1){
    Base* command = new Command(cmd);
    parsingTree.push(command);
  }
  else if(cmd.find(' ') != -1){
    bool whileCondition = true;
    bool first = true;
    while(whileCondition == true){
      int space = cmd.find(' ');
      int spaceCount = 0;
      for(int i = 0; i < cmd.size(); i++){
        if(cmd.at(i) == ' '){spaceCount++;}
      }

    // if(cmd.substr(0,4) == "test" || cmd.at(0) == '['){
    //     if(cmd.find('&') == -1 && cmd.find(';' == -1 && cmd.find('|') == -1)){
    //             Base* TestCmd = new TestCommand(cmd);
    //             parsingTree.push(TestCmd);
    //             whileCondition = false;
    //             break;
    //
    //             }
    //   }

      if(first == false){
        if(spaceCount == 0){
          parsingTree.push(new Command(cmd));
          whileCondition = false;
          break;
        }
        string copy = cmd.substr(cmd.find(' '), cmd.size() - 1);
        space = copy.find(' ');
      }

      if(cmd.at(space + 1) != '&' && cmd.at(space + 1) != '|' && cmd.at(space + 1) != ';'){

        //Condition to check for the '&&' operator
        if(cmd.find('&') != -1){
          int andOperator = cmd.find('&');
          Base* firstCommand = new Command(cmd.substr(0, andOperator - 1));
          if(firstCommand->getCommand().at(0) == '[' || firstCommand->getCommand().substr(0,4) == "test"){
              firstCommand = new TestCommand(cmd.substr(0, andOperator - 1));
          }
          Base* secondCommand = new Command(cmd.substr(andOperator + 3, cmd.size() - 1));
          Base* andCondition = new andConnector(firstCommand, secondCommand);
          parsingTree.push(andCondition);
          cmd = secondCommand->getCommand();
          first = false;
        }

        //Condition to check for the '||' operator
        if(cmd.find('|') != -1){
          int orOperator = cmd.find('|');
          Base* firstCommand = new Command(cmd.substr(0, orOperator -1));
          if(firstCommand->getCommand().at(0) == '[' || firstCommand->getCommand().substr(0,4) == "test"){
              firstCommand = new TestCommand(cmd.substr(0, orOperator - 1));
          }
          Base* secondCommand = new Command(cmd.substr(orOperator +3, cmd.size() - 1));
          Base* orCondition = new orConnector(firstCommand, secondCommand);
          parsingTree.push(orCondition);
          cmd = secondCommand->getCommand();
          first = false;
        }

        //Condition to check for the ';' operator
        if(cmd.find(';') != -1 ){
          int semiOperator = cmd.find(';');
          Base* firstCommand = new Command(cmd.substr(0, semiOperator));

          // if(firstCommand->getCommand().at(0) == '[' || firstCommand->getCommand().substr(0.4) == "test"){
          //     firstCommand = new TestCommand(cmd.substr(0, semiOperator - 1));
          // }
          
          Base* secondCommand = new Command(cmd.substr(semiOperator + 2, cmd.size() - 1));
          Base* semiCondition = new semiConnector(firstCommand, secondCommand);
          parsingTree.push(semiCondition);
          cmd = secondCommand->getCommand();
          first = false;

        }else{
          Base* elseCondition = new Command(cmd);
          parsingTree.push(elseCondition);
          whileCondition = false;
        }
      }
     if(cmd.at(1) == '[' || cmd.substr(0,4) == "test"){
         TestCommand* anotherTemp = new TestCommand(cmd);
         parsingTree.push(anotherTemp);
         whileCondition = false;
     }
    }
  }
}

  /**
  Function to output commands executed.
  If parsingTree() is not empty,
  Execute all functions within the stack
  **/
  while(!parsingTree.empty()){
    //Output which command executed
    cout << "command executed: " << parsingTree.top()->getCommand() << endl;
    root = parsingTree.top();
    parsingTree.pop();
  }
  root->execute();
}
