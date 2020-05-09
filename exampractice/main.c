#include <stdio.h>
#include <stdlib.h>
#include <float.h>


void permute(int *taken,float *sol,float *ar,float *best_sol,int pos,int N,float *min,float *max,float *best_diff);
void evaluate(float *sol,float *best_sol,float *best_diff,float *min,float *max,int N);
int main()
{
    float ar[10]={1, -2, 3, 14, -5, 16, 7, 8, -9, 120};
    float sol[10]={0};
    float best_sol[10]={0};
    int taken[10]={0};
    int pos=0;
    float min,max,best_diff;
    permute(taken,sol,ar,best_sol,pos,10,&min,&max,&best_diff);
    for(int i=0;i<10;i++){
        printf("%f\n",best_sol[i]);
    }
    printf("min = %f, max = %f",min,max);
    return 0;
}
void permute(int *taken,float *sol,float *ar,float *best_sol,int pos,int N,float *min,float *max,float *best_diff){
     int i;
     if(pos>=N){
        evaluate(sol,best_sol,best_diff,min,max,N);
     }
     for(i=0;i<N;i++){
        if(taken[i]!=1){
            taken[i]=1;
            sol[pos]=ar[i];
            permute(taken,sol,ar,best_sol,pos+1,N,min,max,best_diff);
            taken[i]=0;
        }
     }
     return ;
}
void evaluate(float *sol,float *best_sol,float *best_diff,float *min,float *max,int N){
     float tot=0;
     int i=0;
     float cmin=FLT_MAX,cmax=FLT_MIN;
     for(i=0;i<N;i++){
        tot+=sol[i];
        cmin=tot<cmin?tot:cmin;
        cmax=tot>cmax?tot:cmax;
     }
     if((cmax-cmin)<*best_diff){
        *best_diff=cmax-cmin;
         for(i=0;i<N;i++)
            best_sol[i]=sol[i];
        *min=cmin;
        *max=cmax;
     }
     return ;
}
