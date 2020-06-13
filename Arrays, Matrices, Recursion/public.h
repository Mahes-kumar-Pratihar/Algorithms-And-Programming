#include "private.h"
void disposeList(list_t *head); // general program for disposing any list
list_t *list_create(list_t *head, int v[], int vSize);// creates list by providing array "v" and it's size "vSize" (add element in head)
void printingList(list_t *head);// given any list head it prints

int area(FILE *fp);// function to find area of rectangle with overlapping area to be considered once only

void split(list_t **head, int threshold, list_t **head1, list_t **head2);// given head of list and threshold it splits in two with
                                                                         // elements < threshold(head1) and elements >= threshold(head2)
                                                                         // notice provide &head1 and &head2 to prototype not head1 and head2

void powerset(int *switchesArray, int *sol, int k, int *bulbsState, int bulbs, int mat[][5]);// finding power sets using combinations

// finding possible sets of switches which can be pressed to turn on all bulbs
void powerset_combinatios_r(int *switchesArray, int *sol, int k, int n, int pos, int start, int mat[][5], int *bulbsState, int bulbs, int *switches);
