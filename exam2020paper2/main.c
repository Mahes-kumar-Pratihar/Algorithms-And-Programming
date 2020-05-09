#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int ch = 0;
void generate (char *str, int n, int m);

void recursive_function(char *str, int sol[], int *mark, int level, int n, int m);
int main()
{
    char *str = "111223";
    int n = 2, m = 5;
    generate(str, n, m);
    return 0;
}
void generate(char *str, int n, int m){
     int *s = (int *)malloc(n * sizeof(int));
     int sol[2]={0};
     int *mark = (int *)malloc(strlen(str) * sizeof(int));
     int level = 0;
     for(int i = 0; i < strlen(str); i++){
        mark[i] = 0;
     }
     recursive_function(str, sol, mark, level, n, m);
     printf(".");
}

void recursive_function(char *str, int sol[], int *mark, int level, int n, int m){
     int i;
     if(level >= n){
        int sum;

        for(i = 0, sum = 0; i < n; i++){
            sum += sol[i];
        }

        if(sum == m){
             if(ch > 0){
                printf(", ");
             }
            ch = 1;
            printf("%c", '{');
            for(i = 0; i < n; i++){
                printf("%d", sol[i]);
                if(i <= n-2){
                    printf(", ");
                }
            }
            printf("%c", '}');
        }
        return;
     }
     for(i = 0; i < strlen(str); i++){
        if(mark[i] == 0){
          mark[i] = 1;
          sol[level] = str[i] - 48;
          recursive_function(str, sol, mark, level + 1, n, m);
          mark[i] = 0;
        }
     }


}
