#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structure.h"

graph_t *graph_allocate(){
    graph_t *graph = malloc(sizeof(graph_t));
    graph->head = NULL;
    graph->n = 0;
    return graph;
}
graph_t *graph_read(char *filename){

    FILE *fp;
    fp = fopen(filename, "r");

    char s1[20], s2[20];
    int weight;
    vertex_t *vertex1, *vertex2;
    graph_t  *graph = graph_allocate();
    while(fscanf(fp,"%s %d %s", s1, &weight, s2) != EOF){
          vertex1 = find_vertex(graph, s1);
          if(vertex1 == NULL){
            vertex_add(graph, s1);
            vertex1 = graph->head;
          }
          vertex2 = find_vertex(graph, s2);
          if(vertex2 == NULL){
            vertex_add(graph, s2);
            vertex2 = graph->head;
          }
          edge_add(vertex1, vertex2, weight);
          edge_add(vertex2, vertex1, weight);
    }

    return graph;
}
vertex_t *find_vertex(graph_t *graph, char *id){
       vertex_t *vertex = graph->head;
       while(vertex != NULL){
           if(strcmp(vertex->id, id) == 0){
            return vertex;
           }
           vertex = vertex->next;
       }
       return NULL;
}
void vertex_add(graph_t *graph, char *id){

     vertex_t *vertex = (vertex_t *)malloc(sizeof(vertex_t));
     if(vertex == NULL){
        fprintf(stdout,"Error in allocating vertex!");
        exit(EXIT_FAILURE);
     }
     vertex->id = strdup(id);
     vertex->nIn = 0;
     vertex->nOut = 0;
     vertex->visited = 0;
     vertex->edge = NULL;
     vertex->next = NULL;
     vertex->hasAtm = 0;
     vertex->next = graph->head;
     graph->head = vertex;
     graph->n++;

     return;
}
void edge_add(vertex_t *vertex1, vertex_t *vertex2, int weight){
     edge_t *edge = (edge_t *)malloc(sizeof(edge));
     if(edge == NULL){
        fprintf(stdout,"Error in allocating edge!");
        exit(EXIT_FAILURE);
     }

     edge->vertex = vertex2;
     edge->next = vertex1->edge;
     edge->weight = weight;
     vertex1->edge = edge;
     vertex1->nOut++;
     vertex2->nIn++;

     return;
}
void graph_write(graph_t *graph){
    vertex_t *check1 = graph->head;
    edge_t *check2 = NULL;

    while(check1 != NULL){
        printf("%s (nOut=%d) ->", check1->id, check1->nOut);
        check2 = check1->edge;
        while(check2 != NULL){
            printf(" %s(Weight = %d)", check2->vertex->id, check2->weight);
            check2 = check2->next;
        }
        check2 = NULL;
        printf("\n");
        check1 = check1->next;
    }
}
void graph_dispose(graph_t *graph){

     vertex_t *vertex, *vertexTmp;
     edge_t *edge, *edgeTmp;

     vertex = graph->head;
     while(vertex != NULL){
        vertexTmp = vertex->next;

        edge = vertex->edge;
        while(edge != NULL){
            edgeTmp = edge->next;
            free(edge);
            edge = edgeTmp;
        }
        free(vertex);
        vertex = vertexTmp;
     }
     free(edge);
     free(vertex);
     free(graph);

     return;
}

