#include "public.h"




int main(int argc, char **argv)
{   /*
    int mat[N][N] = {
                     {1, 2, 3, 4},
                     {6, 7, 8, 9},
                     {10, 11, 12, 13},
                     {20, 30, 40, 50}
                     };*/
    //printf("Original Matrix");
    /*for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }*/
    //submat_write(mat, 4, 4);
    int *l;
    int N = 3; // no. of piers or platforms
    int L = 10; // size of each pier
    int m = 4; // no. of ships and also size of vector l = {5, 8, 4, 2}
    int v[4] = {5, 8, 4, 2};

    l = (int *)malloc(4 * sizeof(int));
    int max_piers_required;
    int space_occupied_by_ships = 0;
    for(int i = 0; i < 4; i++){
        l[i] = v[i];
        space_occupied_by_ships += v[i];
    }

    max_piers_required =N - (N * L - space_occupied_by_ships)/L;



    printf("Max number of piers required --->>> %d\n", max_piers_required);


    ship_to_port(max_piers_required, L, m, l);
    return 0;
}
void ship_to_port(int N, int L, int m, int *l){
     int *value = malloc(N * sizeof(int));
     int *sol = calloc(m , sizeof(int));
     int *piers = calloc(N , sizeof(int));

     for(int i = 0; i < N; i++)
        value[i] = i + 1;

    arrangements_repeti_r(value, sol, 0, m, N, L, piers, l);


}
void arrangements_repeti_r(int *value, int *sol, int pos, int m, int N, int L, int *piers, int *l){
     int i;

     if(pos >= m){
        correct_setUp(sol, m, N, L, piers, l);
        return ;
     }
     for(i = 0; i < N; i++){
        sol[pos] = value[i];
      arrangements_repeti_r(value, sol, pos + 1, m, N, L, piers, l);
     }
   return ;
}
void correct_setUp(int *sol, int m, int N, int L, int *piers, int *l){
    int i, j;

    for(i = 0; i < m; i++){
        piers[sol[i] - 1] += l[i];
        if(piers[sol[i] - 1] > L){
            //printf(" --->>> Not valid %d!", piers[sol[i]-1]);
            for(j = 0; j < N; j++)
                piers[j] = 0;
            return;
        }
    }
    for(i = 0; i < m; i++)
        printf("(pier -> %d, ship -> %d)", sol[i], l[i]);

    printf("\n");
    return;
}





