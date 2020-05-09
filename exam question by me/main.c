#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
A basic calculator supports only 3 operations on integer decimal numbers: Multiplication, addition, and subtraction.
Moreover operators have the same precedence and they are left associative. For example, the expression 22 − 21 ∗ 79
can be evaluated as (22 − 21) ∗ 79 = 79.
Write the function
void calculator (int *v, int n, int result);
which receives an array v of size n of integer values, and the expression result, and it prints all possible expressions
delivering that result.
For example, if v = { 55, 3, 45, 33, 25 }, n = 5, and result = 404, the required expression is 55 + 3
- 45 * 33 - 25.
*/
void calculator (int *v, int n, int result);
int main(){
    int v[5] = { 10, 10, 4, 2, 2 };
    int n = 5,result = 404;
    calculator(v,n,result);
    return 0;
}
void calculator (int *v, int n, int result){
     char sym[]={'+','-','*','\0'};
     int k=n-1,pos=0;
     char *sol;
     sol=(char *)malloc(k*sizeof(char));
     permutation(v,sol,sym,k,pos,n,result);
     free(sol);
     return 0;
}
void permutation(int *v,char *sol,char *sym,int k,int pos,int n,int result){
     int i=0,sum=0;
     if(pos>=k){
        if(sol[0]=='+')
           sum=v[0]+v[1];
        else if(sol[0]=='-')
             sum=v[0]-v[1];
        else if(sol[0]=='*')
             sum=v[0]*v[1];
        for(i=2;i<n;i++){
            if(sol[i-1]=='+')
                sum+=v[i];
            else if(sol[i-1]=='-')
                 sum-=v[i];
            else if(sol[i-1]=='*')
                 sum*=v[i];
        }
        if(sum==result){
           for(i=0;i<n;i++){
               if(i<k)
                  printf("%d%c",v[i],sol[i]);
               else
                  printf("%d\n",v[i]);
           }
        }
     return;
     }
     for(i=0;i<strlen(sym);i++){
        sol[pos]=sym[i];
        permutation(v,sol,sym,k,pos+1,n,result);
     }
     return;
}
