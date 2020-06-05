#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



typedef struct list_s{
        int n;
        struct list_s *next;

}list_t;

void subvet_write(int *v, int n){
     int start = 0, end = 0;
     int max = 0, count = 0;
     int flag = 1;
     for(int i = 0; i < n; i++){// Finding max length sub-array

        if(v[i] != 0)
            count++;
        else if(v[i] == 0){
                if(max < count)
                   max = count;// if length of max sub array is higher than previous max then change max
             count = 0;
        }

     }
     count = 0;

     for(int i = 0; i < n; i++){
        if(flag == 1){
            start = i;// setting up the start of array
            flag = 0;
        }
        if(v[i] != 0)
            count++;
        else{
            count = 0;
            flag = 1;
        }
        if(count == max){// if length is equal to max length then print and set new start by flag = 1
            printf("{");
            for(int j = start; j <= i; j++){
                if(j == i)printf("%d", v[j]);
                else printf("%d,", v[j]);
            }
            printf("}");
            flag = 1;
            count = 0;
        }
     }


}
list_t *create_list(int *v, list_t *head, int arraySize){
        list_t *p = NULL;
        list_t *tail = NULL;
        for(int i = 0; i < arraySize; i++){
            p =(list_t *) malloc(1 * sizeof(list_t));
            p->n = v[i];
            p ->next = NULL;
            if(head == NULL){
                head = p;
                tail = head;
            }else{
                  tail->next = p;
                  tail = p;
            }
        }
        return head;
}
void list_complete(list_t *head){
     list_t *p = head, *q = head->next, *temp = NULL;

     while(q != NULL){
        if(abs(p->n - q->n) > 1){ // finding the difference between two successive nodes of original array if more than 1 add new node
            temp = (list_t *) malloc(1 * sizeof(list_t));
            temp->n = p->n + 1;

            temp->next = q;// inserting new node in middle
            p->next = temp;

            p = p->next;
        }
        else{
            p = q;
            q = q->next;
        }
     }
}

int bestDuration = 0;//Global variable for bestDuration

void activity_selection(int m[5][2], int *bestsol, int n){
     int *value = malloc(n * sizeof(int));
     int *sol = calloc(n , sizeof(int));
     int k = n;// no. of rows in matrix
     printf("Array-Value contains -> ");
     for(int i = 0; i < n; i++){
        value[i] = i;
        printf(" %d", value[i]);
     }
     printf("\n\n");
     power_set(m, value, sol, bestsol, k);
}

void power_set(int m[5][2], int *value, int *sol, int *bestsol, int k){
    int pos = 0;
    int start = 0;
    for(int i = 1; i <= k; i++){
        power_set_vers3_r(m, value, sol, bestsol, k, i, pos, start);
    }

}

void power_set_vers3_r(int m[5][2],int *value, int *sol, int *bestsol, int k, int n, int pos, int start){
    int i;
    if(pos == n){
       /* for(i = 0; i < n; i++)
            printf("%d ", sol[i]);
        printf("\n");*/

        if(has_interSection(m, sol, n))
            return;
        else{
            for(int j = 0; j < k; j++)
                bestsol[j] = 0;
            for(int j = 0; j < n; j++){
                  bestsol[sol[j]] = 1;
            }
            printf("Current Best Solution with BestDuration(%d) ->", bestDuration);
            for(int i = 0; i < k; i++){
                printf(" %d", bestsol[i]);
            }
            printf("\n\n");
        }

        return;
    }
    for(i = start; i < k; i++){
        sol[pos] = value[i];
        power_set_vers3_r(m,value, sol, bestsol, k, n, pos + 1, i + 1);
    }

}
int has_interSection(int m[5][2], int *sol, int n){
    int l, h, l2, h2, i, j;
    int currentDuration = 0;
    int flag = 1;
    printf("Possible Solution -> ");
    for(i = 0; i < n; i++)
        printf("(index = %d){%d, %d}",sol[i], m[sol[i]][0], m[sol[i]][1]);

    currentDuration += (m[sol[0]][1] - m[sol[0]][0]);

    for(i = 0; i < n; i++){
        l = m[sol[i]][0];
        h = m[sol[i]][1];

        for(j = i + 1; j < n; j++){
           l2 = m[sol[j]][0];
           h2 = m[sol[j]][1];

           if(l <= h2 && l2 <= h){
             printf("There is intersection\n\n");
             return 1;
           }

           if(flag == 1)
              currentDuration+=(h2 - l2);
        }
        flag = 0;
    }
    printf("--> Duration = %d\n\n", currentDuration);
    if(bestDuration < currentDuration)
       bestDuration = currentDuration;
    else{
         printf("CurrentDuration(%d) is not better than BestDuration(%d)\n\n", currentDuration, bestDuration);
         return 1;
    }

    return 0;
}

