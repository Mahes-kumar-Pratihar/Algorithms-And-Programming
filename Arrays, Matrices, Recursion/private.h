#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define N 10 // size of 10x10 matrix used to find covered area by rectangles
int numSwitches = 100;


typedef struct list_s{
        int value;
        struct list_s *next;
}list_t;

// prototypes in public.h

list_t *list_create(list_t *head, int v[], int vSize){
       list_t *p = NULL;
       int i = 0;
       for(; i < vSize; i++){
        if(head == NULL){
            head = malloc(sizeof(list_t));
            head->value = v[i];
            head->next = NULL;
        }
        else{
            p = malloc(sizeof(list_t));
            p->value = v[i];
            p->next = head;
            head = p;
        }
       }
       return head;
}

void printingList(list_t *head){
     list_t *tmp;
     tmp = head;
     while(tmp != NULL){
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");

}
void disposeList(list_t *head){
     list_t *tmp;
     while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
     }
}




int area(FILE *fp){
    char mat[N][N];
    int x1, y1;
    int x2, y2;
    int count = 0;
    int i = 0;
    int j = 0;

    printf("Points of rectangles : \n");
    while(fscanf(fp,"%d %d %d %d", &x1, &y1, &x2, &y2) != EOF){
       printf("(%d,%d), (%d,%d)\n", x1, y1, x2, y2);
       for(i = y1 - 1; i < y2 - 1; i++){
        for(j = x1 - 1; j < x2 - 1; j++)
            mat[i][j] = '*';
       }
    }
    // printing the area;
   printf("\n\nArea covered by rectangles : \n\n");
   for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(mat[i][j] == '*')
               printf("%c", mat[i][j]);
            else
                printf(".");
        }
        printf("\n");
    }
    // counting the area
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(mat[i][j] == '*')
                count++;
        }
    }

    return count;
}

void split(list_t **head, int threshold, list_t **head1, list_t **head2){
    list_t *h = *head, *h1 = *head1, *h2 = *head2;
    list_t *tmp = NULL;

    while(h != NULL){
        tmp = malloc(sizeof(list_t));
        tmp->value = h->value;
        tmp->next = NULL;

        if(h->value < threshold){
            tmp->next = h1;
            h1 = tmp;
        }
        if(h->value >= threshold){
            tmp->next = h2;
            h2 = tmp;
        }

        h = h->next;
    }

    *head1 = h1;
    *head2 = h2;

}


void powerset(int *switchesArray, int *sol, int k, int *bulbsState, int bulbs, int mat[][5]){
    int *switches = malloc(k * sizeof(int));
    int i;
    for(i = 1; i <= k; i++){
        powerset_combinatios_r(switchesArray, sol, k, i, 0, 0, mat, bulbsState, bulbs, switches);
    }


    printf("\n\n\nSwitches need to be pressed in order to TURN OFF all the BULBS --->>>>> ");

    for(i = 0; i < numSwitches; i++){
        printf("%d ", switches[i] + 1);
    }
    printf("\n\n\n");
    free(switches);
}
void powerset_combinatios_r(int *switchesArray, int *sol, int k, int n, int pos, int start, int mat[][5], int *bulbsState, int bulbs, int *switches){
     int i, j;
     if(pos == n){
        //printf("\nPressing Switches -> ");
        //for(i = 0; i < n; i++){
        //    printf("%d ", sol[i]);
       // }

        for(i = 0; i < n; i++){
           for(j = 0; j < bulbs; j++){
             if(bulbsState[j] == 1)// if bulb is already on then turn off
                bulbsState[j] -= mat[sol[i]][j];
             else
                bulbsState[j] = mat[sol[i]][j];
           }
        }
       // printf(" ->> BulbStates -> ");
        //for(i = 0; i < bulbs; i++)
        //    printf("%d ", bulbsState[i]);
        //printf("\n");

        for(i = 0; i < bulbs; i++){
            if(bulbsState[i] == 0){
                   // printf(" ->>> NO");
                for(j = 0; j < bulbs; j++)
                    bulbsState[j] = 0;// if combination of switches is not valid then put states of bulbs to off
                return;
            }
        }
        if(numSwitches > n){// checking if number of switches less then last combination
            //printf(" ->>> YES");
            numSwitches = n;
            for(i = 0; i < n; i++)
                switches[i] = sol[i];// saving the combination of valid switches
            for(j = 0; j < bulbs; j++)// if combination of switches is valid then put states of bulbs to off to find another
                    bulbsState[j] = 0;// switch combination
            return;
        }
     }
     for(i = start; i < k; i++){
        sol[pos] = switchesArray[i];
        powerset_combinatios_r(switchesArray, sol, k, n, pos + 1, i + 1, mat,bulbsState, bulbs, switches);
     }

     return;
}

