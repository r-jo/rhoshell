#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main(){
    pid_t child;
    int childStatus;

    child = fork();
    
    if(child == 0){
       execvp(argv[0], argv);
        cout << "no value was entered" << endl;
    }
    else{
        pid_t waitChild = wait(&childStatus);
        return childStatus;
    }
}
void parser(char ln, char **argv){
    while(ln != '\0'){
        **argv++ = ln;
        while(ln != ' ' && ln != '\n'){
            ln++;
        }
    }
}


