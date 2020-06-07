#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int UNSAT;


typedef struct data{
        int *input;
        int *inputBinaryform;
        int numInput;
        int result;
}clause_t;

void read_file(char *filename){
     FILE *fp;
     int numClauses;
     int numVariables;
     clause_t *clauses;

     fp = fopen(filename, "r");

     if(fp == NULL){
        fprintf(stdout,"Error in reading the file");
        exit(EXIT_FAILURE);
     }

     fscanf(fp,"%d %d", &numClauses, &numVariables);

     fprintf(stdout,"No. of clauses ->> %d\nNo. of variables ->> %d\n", numClauses, numVariables);

     clauses = malloc(numClauses * sizeof(clause_t));

     int i = 0, j;
     int numVariablesInClause;

     while(fscanf(fp,"%d", &numVariablesInClause)!= EOF){

           clauses[i].input = (int *)malloc(numVariablesInClause * sizeof(int));
           clauses[i].inputBinaryform = (int *)malloc(numVariablesInClause * sizeof(int));
           clauses[i].numInput = numVariablesInClause;
           clauses[i].result = 0;
           for(j = 0; j < numVariablesInClause; j++){
            fscanf(fp,"%d", &clauses[i].input[j]);
           }
        i++;
     }

     for(i = 0; i < numClauses; i++){
            printf("Clause %d with %d variables ->> ", i, clauses[i].numInput);
        for(j = 0; j < clauses[i].numInput; j++){
            printf(" %d", clauses[i].input[j]);
        }
        printf("\n");
     }
     printf("\n");

     int *sol = malloc(numVariables * sizeof(int));
     int BASE = 2;
     int pos = 0;
     int k = numVariables;

     binary_generation_r(BASE, sol, pos, k, clauses, numClauses);
     if(UNSAT == 0){
        fprintf(stdout,"Provided clause is UNSAT");
     }
     dispose(clauses, numClauses);
}

void binary_generation_r(int BASE, int *sol, int pos, int k, clause_t *clauses, int numClauses){
    int i, j, result;
    if(pos >= k){
        //printf("Possible solution -> ");
       // for(i = 0; i < k; i++)
        //    printf("%d ", sol[i]);
        filling_clause(sol, numClauses, clauses);
        result = check_solution(clauses, numClauses);
        if(result == 1){
             for(j = 0; j < numClauses; j++)
              clauses[j].result = 0;
             printf("Correct (Mapping)solution -> ");
             UNSAT = 1;
        for(i = 0; i < k; i++)
            printf("%d ", sol[i]);
            printf("\n");
        }
        //printf("\n");
        //printf("\n");
        return;
    }
    for(i = 0; i < 2; i++){
        sol[pos] = i;
        binary_generation_r(BASE, sol, pos + 1, k, clauses, numClauses);
    }
}
void filling_clause(int *sol, int numClauses, clause_t *clauses){

    int i = 0, j = 0;
    int put;
    //printf("\n");
    for(i = 0; i < numClauses; i++){
        for(j = 0; j < clauses[i].numInput; j++){

            if(clauses[i].input[j] < 0){
               put = sol[abs(clauses[i].input[j]) - 1 ];
               if(put == 0)
                clauses[i].inputBinaryform[j] = 1;
               else
                clauses[i].inputBinaryform[j] = 0;
            }
            else{
                clauses[i].inputBinaryform[j] = sol[clauses[i].input[j] - 1 ];
            }

        }
        //printf("inputBinaryForm ->>");
       // for(int k = 0; k < clauses[i].numInput; k++)
       //     printf(" %d", clauses[i].inputBinaryform[k]);

       // printf("\n");
    }

}
int check_solution(clause_t *clauses, int numClauses){
    int i , j;

    for(i = 0; i < numClauses; i++){
        for(j = 0; j < clauses[i].numInput; j++)
        if(clauses[i].inputBinaryform[j] == 1){
               clauses[i].result = 1;
               break;
        }
    }

    for(i = 0; i < numClauses; i++){
        if(clauses[i].result == 0){
           for(j = 0; j < numClauses; j++)
              clauses[j].result = 0;

           return 0;
        }
    }

    return 1;
}
void dispose(clause_t *clauses, int numClauses){
     int i;

     for(i = 0; i < numClauses; i++){
         free(clauses[i].input);
         free(clauses[i].inputBinaryform);
     }
     free(clauses);

     return;
}

