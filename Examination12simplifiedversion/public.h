#include "private.h"

//this function can be used to find all square sub-matrices inside a matrix,
//of size greater than 2x2
void submat_write(int mat[][4], int r, int c);
/*
int mat[3][3] = {
                     {1, 2, 3},
                     {6, 7, 8},
                     {10, 11, 12}
                     };

 result 5 sub-matrices
  1 2    2 3   6  7     7  8      1   2   3
  6 7,   7 8,  10 11,   11 12,    6   7   8
                                  10  11  12

*/

void ship_to_port(int N, int L, int m, int *l);// function to find
void arrangements_repeti_r(int *value, int *sol, int pos, int m, int N, int L, int *piers, int *l);
void correct_setUp(int *sol, int m, int N, int L, int *piers, int *l);
