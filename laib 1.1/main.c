#include <stdio.h>
#include <stdlib.h>
#define DIM 15
int main()
{
    int mtx[DIM]={2  , 3   ,4  ,-1  ,-10   ,5   ,6  , 8   ,11  ,-9   ,8  ,-10 ,  9  , 3   ,0};
    int i=0,j=0,start_pos=0,final_pos=0,length1=0,length2=0,flag=1;

    for(;i<DIM;i++){

        for(j=i;j<DIM && flag==1;j++){
                if(mtx[j]<mtx[j+1])
                   length1++;
                else{
                    flag=0;
                       if(length1>length2){
                            length2=length1;
                            length1=0;
                            start_pos=i;
                            final_pos=j;
                        }
                }

      }
      j=j-1;
      flag=1;
      length1=0;
    }
    for(i=start_pos;i<=final_pos;i++)
        printf("% d ",mtx[i]);
    return 0;
}
