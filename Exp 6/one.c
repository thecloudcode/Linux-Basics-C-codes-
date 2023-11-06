#include <stdio.h>
#include <string.h>
#include <pthread.h>

char res[20];
char strings[3][7] = {
    "I ", "am ", "Batman"
};

void* concat(void* arg){
    int t_id = *(int *)arg;
    strcat(res, strings[t_id]);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[3];
    int t_ids[3];
    
    res[0]='\0';
    for(int i=0;i<3;i++){
        t_ids[i]=i;
        pthread_create(&threads[i], NULL, concat, &t_ids[i]);
    }

    for(int i=0;i<3;i++) pthread_join(threads[i], NULL);

    printf("%s\n",res);

    return 0;
}


