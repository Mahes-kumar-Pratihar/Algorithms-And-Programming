#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 50 + 1
typedef struct item_s{
        char *item_name;
        int weight;
        int price;
        int availability;

        int count;
        int n_weight;
        int n_price;
}item_t;

int bestPrice = 0;
int solCount = 1;

item_t *file_read(char *filename, int *n_items);

void sol_recur(item_t *, item_t *, int, int,int *, int, int, item_t *, int *);

int check_item(char *, item_t *, int, int, int, int);


int main(int argc, char **argv)
{
    int n_items = 0;
    item_t *item_list, *solution, *bestSolution;
    int cart_capacity = atoi(argv[2]);
    int *availability;
    int i, numBestItems = 0;

    item_list = file_read(argv[1], &n_items);

    availability = (int *)malloc(n_items * sizeof(int));
    solution = (item_t *)malloc(n_items * sizeof(item_t));
    bestSolution = (item_t *)malloc(n_items * sizeof(item_t));

    for(i = 0; i < n_items; i++){
        availability[i] = item_list[i].availability;
    }
    sol_recur(item_list, solution, cart_capacity, 0, availability, 0, n_items, bestSolution,&numBestItems);

    printf("\n\n\n******FINAL SOLUTION*******\n\n");
    for(i = 0; i < numBestItems; i++){
        fprintf(stdout,"%s  %d   %d  %d\n", bestSolution[i].item_name, bestSolution[i].n_weight, bestSolution[i].n_price, bestSolution[i].count);
    }


    free(solution);
    free(bestSolution);
    free(availability);
    return 0;
}
item_t *file_read(char *filename, int *n_items){
          item_t *item_list;
          FILE *fp;
          char item_name[MAX_LENGTH];
          int weight;
          int price;
          int availability;
          int count = 0;
          fp = fopen(filename, "r");
          if(fscanf(fp, "%d", n_items) == EOF){
            fprintf(stdout,"File is empty!");
            exit(EXIT_FAILURE);
          }

          item_list = (item_t *)malloc(*n_items * sizeof(item_t));

          while(fscanf(fp, "%s %d %d %d", item_name, &weight, &price, &availability) != EOF){
                item_list[count].item_name = strdup(item_name);
                item_list[count].weight = weight;
                item_list[count].price = price;
                item_list[count].availability = availability;
                item_list[count].count = 0;
                item_list[count].n_price = 0;
                item_list[count++].n_weight = 0;
          }

          return item_list;

}
void sol_recur(item_t *item_list, item_t *solution, int weight, int itemNum,int *availability, int sumWeight, int n_items, item_t *bestSolution, int *numBestItems){

     int i;

     if(sumWeight >= weight){
            int totalPrice = 0;
            int sum = 0;
            for(i = 0; i < itemNum; i++){
                totalPrice += solution[i].n_price;
            }
            printf("-----------\n\n");
            for(i = 0; i < itemNum; i++){
                      fprintf(stdout,"name - %s, n_weight - %d, n_price - %d, count - %d\n", solution[i].item_name, solution[i].n_weight, solution[i].n_price, solution[i].count);
                      sum += solution[i].n_weight;
                   }
                   printf("Total weight -- %d < %d and Total price is %d\n\n", sum, weight, totalPrice);
                   sum = 0;
            if(totalPrice > bestPrice){

                   bestPrice = totalPrice;

                   for(i = 0; i < itemNum; i++){
                    bestSolution[i] = solution[i];
                   }

                   *numBestItems = itemNum;
                   printf("\nSOLUTION NO.--> %d\n",solCount);
                   printf("-----------\n\n");
                   for(i = 0; i < itemNum; i++){
                      fprintf(stdout,"name - %s, n_weight - %d, n_price - %d, count - %d\n", bestSolution[i].item_name, bestSolution[i].n_weight, bestSolution[i].n_price, bestSolution[i].count);
                      sum += bestSolution[i].n_weight;
                   }
                   printf("Total weight -- %d < %d and Total price is %d\n\n", sum, weight, bestPrice);
                   printf("-----------\n\n");
                   solCount++;
                }
            return;
     }

     for(i = 0; i < n_items; i++){
        if(availability[i] != 0){
            availability[i]--;

            if(check_item(item_list[i].item_name, solution, itemNum, item_list[i].weight, item_list[i].price, sumWeight) == 0){

                solution[itemNum] = item_list[i];
                solution[itemNum].n_price = item_list[i].price;
                solution[itemNum].n_weight = item_list[i].weight;
                solution[itemNum].count++;

                sumWeight += item_list[i].weight;
                sol_recur(item_list, solution, weight, itemNum + 1, availability, sumWeight, n_items, bestSolution, numBestItems);
            }

            sumWeight += item_list[i].weight;

            sol_recur(item_list, solution, weight, itemNum, availability, sumWeight, n_items, bestSolution, numBestItems);

            availability[i]++;
        }
     }

     return;

}
int check_item(char *name, item_t *solution, int itemNum, int weight, int price, int sumWeight){
    for(int i = 0; i < itemNum; i++){
        if(strcmp(name, solution[i].item_name) == 0){
           if(sumWeight + weight < 400){
               solution[i].count++;
               solution[i].n_weight += weight;
               solution[i].n_price += price;
           }
           fprintf(stdout,"Checkfunction ->> name - %s, n_weight - %d, n_price - %d, count - %d\n", solution[i].item_name, solution[i].n_weight, solution[i].n_price, solution[i].count);
           return 1;
        }
    }
    return 0;
}
