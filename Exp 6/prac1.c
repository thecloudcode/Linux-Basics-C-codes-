#include<stdio.h>
#include<string.h>
#include<pthread.h>

void* print(void* arg){
    char c = *(char*) arg;
    printf("%c\n",c);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[1];
    char c= 'I';

    pthread_create(&threads[0], NULL, print, &c);

    pthread_join(threads[0], NULL);
    
    return 0;
}