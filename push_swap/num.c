#include<stdio.h>
#include<stdlib.h>  //rand(), srand();
#include<time.h>    //time()
#include<string.h>  //memset()
#define SIZE 10
void mkArr(int* arr, int size){
        int cnt = 0;
        int test[size];
        memset(test,0,size*4);
        srand(time(NULL));
        while(cnt<size){
                int num = rand()%size;
                if(test[num] == 0){
                        test[num] = 1;
                        arr[cnt] = num;
                        cnt++;
                }
        }
}
int main (){
        int arr[SIZE];
        mkArr(arr,SIZE);
        for(int i = 0; i<SIZE; i++){
                printf("%d ",arr[i]);
        }
        return 0;
}
