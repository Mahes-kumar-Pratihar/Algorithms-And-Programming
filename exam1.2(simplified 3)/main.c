#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(int argc,char **argv){
    char alfa[N]={'A','I','O','E','U'};
    char *sol;
    int pos=0;
    int n_char=atoi(argv[1]);
    if(n_char<N){
        printf("Please enter value > %d",n_char,N);
        exit(EXIT_FAILURE);
    }
    sol=(char *)malloc(n_char*sizeof(char));
    recursion(alfa,sol,n_char,pos);
    free(sol);
    return 0;
}
void recursion(char *alfa,char *sol,int n_char,int pos){
     int i=0,j=0,k=0;
     int aux[N]={0};
     if(pos>=n_char){
        for(i=0;i<n_char && k<N;i++){
            for(j=0;j<N;j++){
                if(alfa[j]==sol[i] && aux[j]!=1){
                    aux[j]=1;k++;break;
                }
            }
        }
        if(k==N){
            for(i=0;i<n_char;i++)
                printf("%c",sol[i]);
            printf("\n");
        }
        return;
     }
     for(i=0;i<n_char;i++){
        sol[pos]=alfa[i];
        recursion(alfa,sol,n_char,pos+1);
     }
     return;
}
