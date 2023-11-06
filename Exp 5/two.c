#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid1, pid2;

    printf("%d child, %d parent\n",getpid(),getppid());
    pid1=fork();

    if(pid1==0){
        printf("%d child, %d parent\n",getpid(),getppid());

        pid2=fork();
        if(pid2==0){
            printf("%d child, %parent\n",getpid(),getppid());
        }
    }

    sleep(1);return 0;

}