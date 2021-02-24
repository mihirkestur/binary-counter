#include"assignment_2.h"
#include<stdio.h>
int main()
{
    int n = 7;
    int a[] = {2,3,1,4,5,0,7};

    find_second_greatest(a,n);

    //testing only
    int high = a[0], second_high = a[0];
    for(int i=0;i<n;i++){
        if(a[i]>high){
            if(high>second_high){
                second_high = high;
            }
            high = a[i];
        }
        else if(a[i]>second_high){
            second_high = a[i];
        }
    }
    printf("highest is = %d\nsecond highest is = %d\n",high,second_high);
    return 0;
}