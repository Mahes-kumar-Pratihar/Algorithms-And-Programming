/*
Extend this program with dynamic allocation, i.e.
dynamically allocate an array of structures to store
the list of words read from file and their absolute
frequency.
The number of words stored in the second file is specified
on the first row of the file itself, for example:
   typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
  } index_t;
   typedef struct {
    char *word;
    int occurrences;
  } index_t;*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 20
 typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
  } index_t;
int *malloc_1D(char *,int *);
void find_occurence(char *,index_t *,int );
int main(int argc,char *argv[])
{   index_t *words;
    int numwords=0;
    if(argc!=3){
        fprintf(stderr,"error in no. of args !!");
        exit(EXIT_FAILURE);
    }
    words=malloc_1D(argv[2],&numwords);
    find_occurence(argv[1],words,numwords);
    return 0;
}
int *malloc_1D(char *filename,int *num){
    index_t *vect;
    int numwords=0,i=0;
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL){
        fprintf(stderr,"error in opening the file!!");
        exit(EXIT_FAILURE);
    }
    fscanf(fp,"%d%*c",&numwords);
    vect=(int *)malloc(numwords*sizeof(index_t));
    while(fscanf(fp,"%s",vect[i].word)!=EOF){
        vect[i].occurrences=0;
        i++;
    }
    *num=numwords;
fclose(fp);
return vect;
}
void find_occurence(char *filename,index_t *words,int numwords){
    FILE *fp;
    int i=0,j=0,flag=1;
    char w[MAX_WORD_LENGTH+1];
    fp=fopen(filename,"r");
    if(fp==NULL){
        fprintf(stderr,"error in opening the file!!");
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp,"%s",w)!=EOF){
        for(i=0;i<numwords;i++)
            if(tolower(w[0])==tolower(words[i].word[0])){

                for(j=1;j<strlen(w) && flag==1;j++){
                    if(tolower(w[j])!=tolower(words[i].word[j]))
                        flag=0;
                }

                if(flag==1){
                 words[i].occurrences++;
                 break;
                }
                flag=1;
            }

    flag=1;
    }

    for(i=0;i<numwords;i++){
        printf("%s - %d\n",words[i].word,words[i].occurrences);
    }
    fclose(fp);
}
