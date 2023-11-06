#include<stdio.h>
#include<pthread.h>
#include<string.h>

char iamstring[27];

void* iamstringlen(void* arg) {
    printf("%ld\n", strlen(iamstring));
    pthread_exit(NULL);
}

int main(){
    pthread_t t;

    fgets(iamstring, sizeof(iamstring), stdin);
    pthread_create(&t, NULL, iamstringlen, NULL);
    pthread_join(t,NULL);

    return 0;
}

