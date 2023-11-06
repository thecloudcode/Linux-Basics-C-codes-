#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int arr[7] = {7,6,5,4,3,2,1};
int arrs[7];

void* first(void* arg){
    int s = *(int *)arg;
    int e = s + (7/2);
    int temp;

    for(int i=s;i<e-1;i++){
        for(int j=i+1;j<e;j++){
            if(arr[i]<arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    pthread_exit(NULL);
}

void second(){
    int i = 0, j = 7/2, k = 0;

    while(i<7/2 && j<7){
        if(arr[i] < arr[j]) arrs[k++] = arr[i++];
        else arrs[k++] = arr[j++];
    }

    while(i<7/2) arrs[k++] = arr[i++];
    while(j<7) arrs[k++] = arr[j++];
}

int main(){
    pthread_t threads[3];
    int f=0;
    int third = 0;

    pthread_create(&threads[0], NULL, first, &f);
    f = 7/2;
    pthread_create(&threads[1],NULL,first,&f);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    second();
    for(int i = 6;i>=0;i--) printf("%d ",arr[i]);

    return 0;
}