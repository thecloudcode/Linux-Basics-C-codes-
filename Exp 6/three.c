#include <stdio.h>
#include <pthread.h>

int nums[7]={7,77,7,77,7,77,7};
int avg = 0, max = 0, min = 0;

void* avgf(void *arg){
    int s=0;
    for(int i=0;i<7;i++) s+=nums[i];
    avg = s/7;
    pthread_exit(NULL);
}

void* maxf(void* arg){
    max = nums[0];
    for(int i=0;i<7;i++) if(nums[i]>max) max=nums[i];
    pthread_exit(NULL);
}

void* minf(void* arg){
    min = nums[0];
    for(int i=0;i<7;i++) if(nums[i]<min) min=nums[i];
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[3];

    pthread_create(&threads[0], NULL, avgf, NULL);
    pthread_create(&threads[1], NULL, maxf, NULL);
    pthread_create(&threads[2], NULL, minf, NULL);

    for(int i=0; i<3; i++) pthread_join(threads[i], NULL);

    printf("%d %d %d",avg,max,min);

    return 0;
}
