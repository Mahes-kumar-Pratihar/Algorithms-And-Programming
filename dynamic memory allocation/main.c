#include <stdio.h>
#include <stdlib.h>

int main()//3.8 allocating memory using "malloc"
{
   int n,*p,i=0;
   printf("Enter any number : ");
   scanf("%d",&n);

   p=(int *)malloc(n*sizeof(int));
   if(p==NULL){
    fprintf(stderr,"Error in allocating the memory !!");
    exit(1);
   }

   for(i=0;i<n;i++)
    scanf("%d",(p+i));// or scanf("%d",&p[i]); because after allocation now p is an 1-D array

   printf("\n\n\n");
   for(i=n-1;i>=0;i--)
    printf("%d\n",*(p+i));// or printf("%d\n",p[i]);

   free(p);

    return 0;
}
