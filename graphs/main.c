#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 21

#define DEBUG 1

typedef struct vertex_s{
    char *id;
    int nIn,nOut;
    int visited;
}vetex_t;

typedef struct graph_s{
    int n;
    vetex_t *vertex;
    int **adj;
}graph_t;

typedef struct sol_s{
    int *path;
    int *weight;
    int len;
    int sum;
}sol_t;

graph_t *graph_init();
graph_t *file_read(char *);
int vertex_find(graph_t *,char *);
void vertex_add(graph_t *,char *);
void graph_write(graph_t *);
void graph_dispose(graph_t *);
int main(int argc,char **argv)
{
    graph_t *graph=NULL;
    int i;
    char id[MAX_LEN];
    sol_t best;
    if(argc!=2){
        printf("error in commandline args");exit(EXIT_FAILURE);}

    graph = file_read(argv[1]);
    graph_write(graph);
    return 0;
}
graph_t *file_read(char *name){
    graph_t *graph;
    char name1[MAX_LEN],name2[MAX_LEN];
    int i, j, weight;
    FILE *fp;

    graph = graph_init();

    fp = fopen(name,"r");
    if(fp==NULL){
        printf("error in opening the file");exit(EXIT_FAILURE);}

    while(fscanf(fp,"%s %d %s",name1,&weight,name2) != EOF){
        i = vertex_find(graph,name1);
        if(i<0)vertex_add(graph,name1);

        i = vertex_find(graph,name2);
        if(i<0)vertex_add(graph,name2);
    }

    fclose(fp);

    graph->adj = malloc(graph->n*sizeof(int *));
    if(graph->adj == NULL){
        printf("error in allocating");exit(EXIT_FAILURE);}

    for (i = 0; i<graph->n; i++){
        graph->adj[i] = calloc(graph->n, sizeof(int));
        if(graph->adj == NULL){
        printf("error in allocating");exit(EXIT_FAILURE);}
    }

    fp = fopen(name,"r");
    if(fp==NULL){
        printf("error in opening the file");exit(EXIT_FAILURE);}

    while(fscanf(fp,"%s %d %s",name1,&weight,name2) != EOF){
        i = vertex_find(graph,name1);
        graph->vertex[i].nOut++;
        j = vertex_find(graph,name2);
        graph->vertex[j].nIn++;
        graph->adj[i][j] = weight;
    }

    fclose(fp);
    return graph;

}
graph_t *graph_init(){
    graph_t *g;

    g = malloc(1*sizeof(graph_t));
    if(g == NULL){
        printf("error in allocating");exit(EXIT_FAILURE);}

    g->vertex = NULL;
    g->n = 0;
    g->adj = NULL;

    return g;
}
int vertex_find(graph_t *graph,char *id){
    int i;

    for (i=0 ; i<graph->n; i++){
        if(strcmp(graph->vertex[i].id,id) == 0)
            return i;
    }
    return -1;
}
void vertex_add(graph_t *graph,char *id){
     graph->n++;
     graph->vertex = realloc(graph->vertex, graph->n*sizeof(vetex_t));
     if(graph->vertex == NULL){
        printf("error in allocating");exit(EXIT_FAILURE);}

     graph->vertex[graph->n-1].id = strdup(id);
     graph->vertex[graph->n-1].nIn = 0;
     graph->vertex[graph->n-1].nOut = 0;
     graph->vertex[graph->n-1].visited = 0;

     return;
}
void graph_write(graph_t *graph){
     int i , j;
     fprintf(stdout,"\nGRAPH\n");
     fprintf(stdout,"num of vertices\n",graph->n);
     for (i = 0 ;i < graph->n; i++){
        fprintf(stdout,"#n=%d vertex=%s inDegree=%d outDegree=%d\n",i,graph->vertex[i].id,graph->vertex[i].nIn,graph->vertex[i].nOut);
        for (j = 0; j<graph->n; j++){
            if(graph->adj[i][j] != 0){
                fprintf(stdout," goes to  #%s [Weight = %d]\n",graph->vertex[j].id,graph->adj[i][j]);
            }
        }
        printf("\n");
     }
     return;
}
//fvoid graph_dispose(graph_t *);
