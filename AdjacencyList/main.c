#include "graphFunctions.h"
#include <limits.h>

int max_min_distance = INT_MAX;
void atm_handler_r(graph_t *graph, char **cities,char **sol, char **best_sol,int num_atms, int level, int start);
void fill_cities(char **, graph_t *graph);
int main(int argc, char **argv){

    int num_atms, i;

    char **cities, **sol, ** best_sol;

    graph_t *graph, *temp = NULL;

    num_atms = atoi(argv[2]);

    printf("Number of ATMs is %d\n\n", num_atms);

    sol = (char **)malloc(num_atms * sizeof(char *));
    best_sol = (char **)malloc(num_atms * sizeof(char *));

    graph = graph_read(argv[1]);

    cities = (char **)malloc(graph->n * sizeof(char**));
    fill_cities(cities, graph);
    atm_handler_r(graph, cities, sol, best_sol, num_atms, 0, 0);

    cities[2] = strdup("Mahesh");
    for(i = 0; i < graph->n; i++ ){
        printf("%s\n", cities[i]);
    }
    //graph_write(graph);

    graph_dispose(graph);

    return 0;
}

void atm_handler_r(graph_t *graph, char **cities,char **sol, char **best_sol,int num_atms, int level, int start){
     int i;
     if(level >= num_atms){

       graph_t *temp = graph;

       edge_t *edge = NULL;
       i = 0;
       int max = INT_MAX;
       fprintf(stdout,"solution -> %s %s\n", sol[0], sol[1]);

       while(temp->head != NULL){
          if(strcmp(sol[i++], temp->head->id) == 0){
             edge = temp->head->edge;
             while(edge != NULL){
                if(max > edge->weight){
                    max = edge->weight;
                }
                edge = edge->next;
             }
          }
          edge = NULL;
          temp->head = temp->head->next;
       }

       if(max < max_min_distance){
          max_min_distance = max;
          for(i = 0; i < num_atms; i++)
              best_sol[i] = strdup(sol[i]);

              fprintf(stdout,"Best solution -> %s %s\n\n", best_sol[0], best_sol[1]);
       }
       return;
     }

     for(i = start; i < num_atms; i++){
        sol[level] = strdup(cities[i]);
        atm_handler_r(graph, cities, sol, best_sol, num_atms, level + 1, i + 1);
     }
     return;
}
void fill_cities(char **cities, graph_t *graph){
    graph_t *temp = graph;
    int i = 0;

    while(temp->head != NULL){
         cities[i] = strdup(temp->head->id);
         temp->head = temp->head->next;
         i++;
    }
}
