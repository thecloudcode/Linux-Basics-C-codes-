#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void createChildProcesses(int n){
    for(int i=0;i<(1<<n)-1;i++){
        pid_t pid=fork();
        
        if(pid==0){
            printf("%d created, parent %d\n",getpid());
            createChildProcesses(n-1);
            exit(0);
        }
    }
}

int main(){
    int n=3;
    createChildProcesses(n);
    sleep(1);
    return 0;
}