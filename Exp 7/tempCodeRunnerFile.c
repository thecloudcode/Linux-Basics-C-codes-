// Program to stimulate a race condition

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 5;

void* func1(){
    int local;

    local = shared;
    local = local + 1;

    sleep(1);

    shared = local;
    printf("Shared: %d\n",local);
    pthread_exit(NULL);
}

void* func2(){
    int local;

    local = shared;
    local = local - 1;

    sleep(1);

    shared = local;
    printf("Shared: %d\n", local);
    pthread_exit(NULL);
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}