#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>

int main(){
    pid_t p1,p2,p3,p4,p5;

    p1=fork();
    if(p1==0){
        printf("%d child, %d parent", getpid(), getppid());
        
        p2=fork();
        
        if(p2==0){
            printf("%d child, %d parent", getpid(), getppid());
            p3=fork();

            if(p3==0){
                printf("%d child, %d parent", getpid(), getppid());
                sleep(2);
            }else{
                wait(NULL);
            }
        
        }else{  
            p4=fork();

            if(p4==0){
                printf("%d child, %d parent", getpid(), getppid());
                p5=fork();

                if(p5==0){
                    printf("%d child, %d parent", getpid(), getppid());
                    exit(0);
                }else{
                    sleep(3);
                }
            }else{
                sleep(2);
            }
        }
    }else{
        sleep(5);
    }   
}