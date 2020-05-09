#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BASE 2
void foo(int **n,int l);
int main(){
    int A[6]={23,235,63,73,11,0};
    merge_sort(A,6);
    for(int i=0;i<6;i++)
        printf("%d\n",A[i]);
}
void merge_sort (int *A, int N) {
int l=0, r=N-1;
int *B = (int *)malloc(N*sizeof(int));
merge_sort_r (A, B, l, r);
free(B);
}
void merge_sort_r (int *A, int *B, int l, int r){
int c;
if (r <= l)
return;
c = (l + r)/2;
merge_sort_r (A, B, l, c);
merge_sort_r (A, B, c+1, r);
merge (A, B, l, c, r);
}
void merge (int *A, int *B, int l, int c, int r) {
int i, j, k;
for (i=l, j=c+1, k=l; i<=c && j<=r; )
if (A[i]<=A[j])
B[k++] = A[i++];
else
B[k++] = A[j++];
while (i<=c)
B[k++]=A[i++];
while (j<=r)
B[k++]=A[j++];
for (k=l; k<=r; k++)
A[k] = B[k];
return;
}
