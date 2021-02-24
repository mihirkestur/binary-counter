#include "assignment_2.h"
#include<stdio.h>
typedef struct ds{
    int data;
    int *next;
    struct ds *up;
    struct ds *down;
}matrix;
void print(int *numbers,int n){
    for(int i=0;i<n;i++){
        printf("%d",numbers[i]);
    }
    printf("\n");
}
void find_second_greatest(int *numbers, int length){
}