#include <stdio.h>
#include <stdlib.h>
#define N 8
void rec(int board[N][N], int nums[N*N], int sol[N], int num2[N*N], int level,int start);
int board_check(int board[N][N]);
int check2(int board[N][N], int r, int c);
int main()
{

    int level = 0;
    int board[N][N];
    int nums[64];
    int num2[64] = {0};
    int i;
    int start = 0;
    for(i = 0; i < 64; i++)
        nums[i] = i;

    void rec(board,bnums, sol, num2, level, start);
    return 0;
}
void rec(int board[N][N], int nums[N*N], int sol[N], int num2[N*N], int level,int start){
     int i;

     if(level >= N){
       int j, k, l = 0;
       for(j = 0; j < N; j++){
        num2[sol[j]] = -1;
       }
       for(j = 0; j < N; j++){
           for(k = 0; k < N; k++){
            board[j][k] = num2[l++];
           }
       }
       if(board_check(board)){
          for(j = 0; j < N; j++){
             for(k = 0; k < N; k++){
                if(board[j][k] == -1)
                   printf("$");
                else
                   printf(".");
             }
          }
       }
     }
     for(i = start; i < N; i++){
        sol[level] = nums[i];
        rec(board, nums, sol, num2, level + 1, i + 1);
     }
}
int board_check(int board[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(board[i][j] == -1){
                if(!check2(board, i, j))
                    return 0;
            }
        }
    }
    return 1;
}
int check2(int board[N][N], int r, int c){
    int i, j;
    // row
    for(i = c + 1; i < N; i++){
        if(board[r][i] == -1)
            return 0;
    }
    for(j = c - 1; j >= 0; j--){
        if(board[r][j] == -1)
            return 0;
    }

    //column
    for(i = r + 1; i < N; i++){
        if(board[i][c] == -1)
            return 0;
    }
    for(j = r - 1; j >= 0; j--){
        if(board[j][c] == -1)
            return 0;
    }
    //left diagonal
    for(i = r - 1, j = c - 1; i >= 0 && c >= 0; i--, j--){
        if(board[i][j] == -1){
            return 0;
        }
    }
    for(i = r + 1, j = c + 1; i < N && c < N; i++, j++){
        if(board[i][j] == -1)
            return 0;
    }

    //right diagonal
    for(i = r - 1, j = c + 1; i >= 0 && c < N; i--, j++){
        if(board[i][j] == -1){
            return 0;
        }
    }
    for(i = r + 1, j = c - 1; i < N && c >= 0; i++, j--){
        if(board[i][j] == -1)
            return 0;
    }

    return 1;
}
