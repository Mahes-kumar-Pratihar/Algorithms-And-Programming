#include <stdio.h>
#include <stdlib.h>


int c = 1;
void solve();
void merge_sort (int *A, int N);
void merge_sort_r (int *A, int *B, int l, int r);
void merge (int *A, int *B, int l, int c, int r);
int N[100000];
int n, b;
int main()
{
   int tests = 0;


   int i = 0, k = 0;

   scanf("%d", &tests);

    while(tests--)
    solve(N, n, b);

}


void solve(){
     int i = 0;
     int count = 0;

     scanf("%d%d",&n,&b);
     for(i = 0; i < n; i++){
        scanf("%d",&N[i]);
     }
     merge_sort(N, n);
     for(i = 0; i < n; i++){
        if(b >= N[i]){
            count++;
            b -= N[i];
        }
     }
     printf("Case #%d: %d\n", c, count);
     c++;
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
