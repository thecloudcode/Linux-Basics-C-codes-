#include<stdio.h>
#include<pthread.h>

void* threadFunction(void* arg){
    int res = 17;
    pthread_exit((void*)res);
}

int main(){
    pthread_t thread;
    void* res;

    pthread_create(&thread, NULL, threadFunction, NULL);

    pthread_join(thread, &res);
    int ress = (int)res;
    printf("We got: %d\n",ress);
    return 0;
}