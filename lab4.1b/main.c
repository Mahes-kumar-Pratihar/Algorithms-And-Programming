#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    char *word;
    int occurrences;
  } index_t;
int main(int argc,char *argv)
{

    return 0;
}
int malloc_1D(char *filename){
    FILE *fp;
    index_t words
    int numwords;
    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("error in opening the file");
        exit(EXIT_FAILURE);
    }
    fscanf(fp,"%d%*c",&numwords);

}
