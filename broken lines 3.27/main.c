#include <stdio.h>
#include <stdlib.h>

typedef struct{
               int x1,y1,x2,y2;
               int used1,used2;
              }segments_t;

segments_t *load(char *,int *);
void connect(segments_t *,int);
void check(segments_t *,int);

int main(int argc,char *argv[])
{

    return 0;
}
/*
 * Load the input file contents
 */
segments_t *load(char *name,int *n){
    int i=0,x1,y1,x2,y2;
    segments_t *segments;
    FILE *fin;

    fin=fopen(name,"r");
    if(fin==NULL){
        fprintf(stderr,"Error in opening the file !!\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fin,"%d",n);
    segments=(segments_t *)malloc(*n*sizeof(segments_t));
    if(segments==NULL){
         fprintf(stderr,"Error in  allocating the memory for segments !!\n");
        exit(EXIT_FAILURE);
    }

    while(i<*n && fscanf(fin,"%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF){
        (segments+i)->x1=x1;
        (segments+i)->y1=y1;
        (segments+i)->x2=x2;
        (segments+i)->y2=y2;
        (segments+i)->used1=0;
        (segments+i)->used2=0;
        i++;
    }
    *n=i;
    fclose(fin);
    return segments;
}
/*
*  search for connected segments
*/
void connect(segments_t *segments,int n){
}
