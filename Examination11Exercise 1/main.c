#include "private.h"

#define N 20




int main(int argc, char **argv)
{
    //int v[N] = {1, 0, 2, 3, -1, 0, 4, 5, 0, -2, 3, 4, 8, 0, 0, 0, 3, -1, 10, 6};
    //subvet_write(v, N);// for creating max length sub-array from above array

    //list_t *head = NULL, *temp;

   // int v[3] = {4, 7, 10};

    //head = create_list(v, head, 3);// creating initial list

   // temp = head;
    /* For printing earlier list
    for(;temp != NULL; temp = temp->next){
        printf("%d ", temp->n);
    }
    */
    //list_complete(head);

    //temp = head;
    //for(;temp != NULL; temp = temp->next){// printing final list
   //     printf("%d ", temp->n);
    //}

    int m[5][2]={{1,4},{3,5},{4,6},{5,9},{8,9}};

    int *bestsol = calloc(5, sizeof(int));



    activity_selection(m, bestsol, 5);
    printf("\n\nBest Solution -> ");
    for(int j = 0; j < 5 ; j++){
        printf("%d ", bestsol[j]);
    }
    printf("\n\nAll Intervals -> ");
    for(int i = 0; i < 5; i++){// printing initial 2D- Matrix
        printf("{%d, %d}", m[i][0], m[i][1]);
        if(i < 4)
        printf(", ");
    }
    printf("\n\nBest Solution Intervals Without Intersection -> ");
    for(int j = 0; j < 5; j++){
        if(bestsol[j] != 0)
           printf("{%d, %d}", m[j][0], m[j][1]);
    }
    printf(" --> BestDuration = %d\n\n\n", bestDuration);

    exit(0);
}

