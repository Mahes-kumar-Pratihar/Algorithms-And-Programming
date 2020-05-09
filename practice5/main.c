#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define min(a,b) (a<b) ? a:b
/*
There's a staircase with N steps, and you can climb 1 or 2 steps at a time. Given N,
write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time,
you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
Generalize your function to take in X.
*/

int main () {
   int arr[5]={2,3,4,1,5};
   int count=minimumSwaps(5,arr);
   printf("%d",count);
   return(0);
}

int minimumSwaps(int arr_count, int* arr) {
    int i,j,temp,count=0;
    for(i=0;i<arr_count;i++){
        temp=arr[i];
        for(j=i+1;j<arr_count;j++){
            if(temp>arr[j]){
                count++;
                arr[i]=arr[j];
                arr[j]=temp;
                break;
            }
        }
    }
    return count;
}

