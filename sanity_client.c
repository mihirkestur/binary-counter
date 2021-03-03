#include"assignment_2.h"
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int n;
    int a[1000000];

    //find_second_greatest(a,n);

    //testing only
    srand(time(0));
    n = rand()%10;
    for(int i = 0; i < n; i++){
        a[i] = rand()%10;
    }
    find_second_greatest(a,n);
    int high = a[0], second_high = a[1];
    if(a[0] > a[1]){
        high = a[0];
        second_high = a[1];
    }
    else{
        high = a[1];
        second_high = a[0];
    }
    for(int i=2;i<n;i++){
        if(a[i]>high){
            second_high = high;
            high = a[i];
        }
        else if(a[i]>second_high){
            second_high = a[i];
        }
    }
    printf("highest is = %d\nsecond highest is = %d\n",high,second_high);
    return 0;
}