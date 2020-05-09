#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
void rotate(int [],int,int);
int main()
{
    int a[N] = {0, 1, 2, 3, 4, 5,  6, 7, 8, 9};
    int p;
    for(int i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\nEnter number left and right rotation of array : ");
    scanf("%d",&p);
    rotate(a,p,N);
    return 0;
}
void rotate(int a[],int p,int n){
     int *aux;
     int i;
     int d;
     if(abs(p)>n)
        d=abs(p)%n;
     else
        d=abs(p);
     aux=malloc(d*sizeof(int));
     if(aux==NULL){
        fprintf(stderr,"Error in allocating the memory!");
        return;
     }
     if(p>0){
     for(i=n-d;i<n;i++)
        aux[i-(n-d)]=a[i];
     for(i=N-d-1;i>=0;i--){
        a[i+d]=a[i];
     }
     for(i=0;i<d;i++)
        a[i]=aux[i];
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
     free(aux);
     }
     else{
        for(i=0;i<d;i++)
            aux[i]=a[i];
        for(i=d;i<n;i++)
            a[i-d]=a[i];
        for(i=n-d;i<n;i++)
            a[i]=aux[i-(n-d)];
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        free(aux);
     }
     return;
}
