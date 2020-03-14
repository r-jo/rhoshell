#include "../header/TestCommand.h"

using namespace std;

string TestCommand::getCommand(){
    return cmd;
}

bool TestCommand::execute(){
    string temp;
    string temp2;
    size_t comTest = cmd.find("test");
    size_t flagE = cmd.find("-e");
    size_t flagD = cmd.find("-d");
    size_t flagF = cmd.find("-f");
    size_t initialDash = cmd.find("-");
    struct stat stat_f_comparator;

    if(initialDash != -1){
        if(flagE == -1 && flagD == -1 && flagF == -1){
            cout << "(False)" << endl;
            return 1; //returns false
        }
    }
    //if nothing is choosin choose e as the default
    else if(flagE == -1 && flagD == -1 && flagF == -1){
        if(cmd.at(0) == '[' && cmd.at(cmd.size() - 1) == ']'){
            temp = cmd.substr(1, cmd.size() - 2);
            stringstream ss(temp);
            ss >> temp2;
            temp = temp2;
        }
        else{
            temp = cmd.substr(5);
            cout << temp << endl;
        }
        if (stat(temp.c_str(), &stat_f_comparator) == 0){
            cout << "(True)" << endl;
            return 0;
        }
        else{
            cout << "(False)" << endl;
            return 1;
        }
    }
    if(flagE != -1){
        if (cmd.at(0) == '[' && cmd.at(cmd.size() - 1) == ']'){
            temp = cmd.substr(flagE + 3, cmd.size() - 2);
            stringstream ss(temp);
            ss >> temp2;
            temp = temp2;
        }
        else{
            temp = cmd.substr(flagE + 3);
        }
        if(stat(temp.c_str(), &stat_f_comparator) == 0) {
            cout << "(True)" << endl;
            return 0;
        }
        else{
            cout << "(False)" << endl;
            return 1;
        }
    }
    if(flagD != -1){
        if(cmd.at(0) == '[' && cmd.at(cmd.size() - 1) == ']'){
            temp = cmd.substr(flagD + 3, cmd.size() - 2);
            stringstream ss(temp);
            ss >> temp2;
            temp = temp2;
        }
        else{
            temp = cmd.substr(flagD + 3);
        }
        if(stat(temp.c_str(), &stat_f_comparator) == 0){   
            if(S_ISDIR(stat_f_comparator.st_mode)){
                cout << "(True)" << endl;
                return 0;
            }
            else{
                cout << "(False)" << endl;
                return 1;
            }
        }
        else{
            cout << "(False)" << endl;
            return 1;
        }
    }
    if(flagF != -1){
        if(cmd.at(0) == '[' && cmd.at(cmd.size() - 1) == ']'){
            temp = cmd.substr(flagF + 3, cmd.size() -2);
            stringstream ss(temp);
            ss >> temp2;
            temp = temp2;
        }
        else{
            temp = cmd.substr(flagF + 3);
        }
        if(stat(temp.c_str(), &stat_f_comparator) == 0){
            if(S_ISREG(stat_f_comparator.st_mode)){
            cout << "(True)" << endl;
            return 0;
            }
            else{
                cout << "(False)" << endl;
                return 1;
           }
        }
        else{
            cout << "(False)" << endl;
            return 1;
        }
    }
    return 1;
}
