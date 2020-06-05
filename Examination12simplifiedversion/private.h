#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


void submat_write(int mat[][4], int r, int c){// this function can be used to find all square sub-matrices inside a matrix,
                                              //of size greater than 2x2
    int i, j, k, m, n;
    int max = 0;
    int count = 0;
    if(r > c){// finding max size square matrix eg r = 3, c = 3 then max = 3 mean 3x3, if r = 2 and c = 4 then max = 2 implies 2x2
        max = c;
    }else{
        max = r;
    }


    for(k = 2; k <= max; k++){ // k implies finding square matrices of size k x k till k = max
        for(i = 0; i <= r - k ; i++){// i and j are for traversing matrix at each co-ordinate with <= r - k and <= c - k
            for(j = 0; j <= c - k; j++){
                    printf("Matrix no. %d\n", count + 1);
                for(m = i; m < i + k; m++){// m and n are for printing matrix of size k x k starting from i and j
                    for(n = j; n < j + k; n++){
                        printf("%d ",mat[m][n]);
                    }
                    printf("\n");
                }
                printf("\n\n");
                count++;
            }
        }
    }


}


