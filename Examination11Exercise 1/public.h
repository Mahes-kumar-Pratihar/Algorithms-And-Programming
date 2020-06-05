#include "private.h"

// Exercise 1
void subvet_write(int *v, int n);// for writing max length sub arrays
// Exercise 2
void list_complete(list_t *p);// for creating complete list by giving ascending list eg 4,7,10 -> 4,5,6,7,8,9,10
list_t *create_list(int *, list_t *, int);// for creating list
// Exercise 3
void activity_selection(int m[5][2], int *v, int n);// internally call power set and find the best solution
void power_set(int m[5][2], int *value, int *sol, int *bestsol, int k);// find sets of all orders using power_set_vers3_r
void power_set_vers3_r(int m[5][2], int *value, int *sol, int *bestsol, int k, int n, int pos, int start);// to find power sets
int has_interSection(int m[5][2], int *sol, int n);// take solution which contains matrix indexes and check they have intersection

