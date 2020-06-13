#include "public.h"

int main(int argc, char **argv){

    //Question 10.1
    // two co-ordinates for one rectangle is stored in file data.txt
    // assume 10x10 total size of whole field
    // using these rectangle find area covered by these rectangles and overlapping area should be counted once only
    // result for rectangles in data.txt is ->> 17
    printf("\t\tQuestion 10.1\n\n");
    FILE *fp;
    int AREA = 0;

    if(argc != 2){
        fprintf(stdout,"Error in no. of args !");
        return -1;
    }
    fp = fopen(argv[1],"r");// opening file in read mode

    if(fp == NULL){
        fprintf(stdout,"Error in opening the file 1");
        return -2;
    }

    AREA = area(fp);
    fclose(fp);// closing file
    printf("\n\nArea of all rectangles -->> %d\n\n", AREA);


    // Question 10.2
    // one list is given suppose -> 7, 8, 25, 2, 9, -5, 10, 37
    // write function which splits the list in two lists
    // using threshold mean list 1 contains values < threshold
    // list 2 contains >= threshold
    // note - values must be in same order as in original list
    // example -> threshold = 18
    // list 1 -> 7, 8, 2, 9, -5, 10
    // list 2 -> 25, 37
    printf("\t\tQuestion 10.2\n\n");
    int v[8] = {7, 8, 25, 2, 9, -5, 10, 37};
    list_t *head = NULL, *tmp;
    list_t *head1 = NULL;
    list_t *head2 = NULL;
    int threshold = 18;

    head = list_create(head, v, 8);
    tmp = head;
    // Elements in list
    printf("Printing elements in List : \n");
    printingList(head);

    split(&head,threshold, &head1, &head2);
    // List 1
    printf("\nPrinting list 1 with values < %d(threshold)\n", threshold);
    printingList(head1);
    // List 2
    printf("\nPrinting list 2 with values >= %d(threshold)\n", threshold);
    printingList(head2);
    disposeList(head);// dispose main list
    disposeList(head1);// dispose list 1 (values < threshold)
    disposeList(head2);// dispose list 2 (values >= threshold)
    printf("\n\n");

    // Question 10.3
    // An electrician want to turn on all the bulbs by pressing minimum no. of switches
    // the effect of pressing a switch is given in a matrix example -> by pressing switch 1 -> bulb 1,2,5 turn on and bulb 3,4 turn off
    // note -> pressing a switch can turn on bulbs but also can turn of if already turn on
    // example -> pressing switch 1 -> turn on bulb 1,2,5 and if after that electrician presses switch 2 -> turning off bulb 1 as pressing
    // switch to affects bulb -> 1,3 and bulb 1 was already on so pressing switch 2 turns bulb 1 off
    // answer -> pressing switch -> 1,2,4 will turn on all the bulbs
    printf("\t\tQuestion 10.3\n\n");
    int mat[4][5] ={{1,1,0,0,1},{1,0,1,0,0},{0,1,1,1,0},{1,0,0,1,0}};
    int switches = 4;
    int bulbs = 5;
    int i = 0, j = 0;

    printf("Effects of pressing switches on bulbs:\n");
    for(i = 0; i < switches; i++){
        printf("Switch -> %d ->> ", i + 1);
        for(j = 0; j < bulbs; j++){
            fprintf(stdout,"%d ",mat[i][j]);
        }
        printf("\n");
    }

    int *bulbsState = calloc(bulbs,sizeof(int));
    int *switchesArray = malloc(switches * sizeof(int));
    int *sol = malloc(switches * sizeof(int));

    for(i = 0; i < switches; i++)
        switchesArray[i] = i;

    powerset(switchesArray, sol, switches, bulbsState, bulbs, mat);

    free(bulbsState);
    free(switchesArray);
    free(sol);

    return 0;
}

