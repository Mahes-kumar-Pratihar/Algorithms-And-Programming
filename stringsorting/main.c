#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 60
char **readfile(char *,int *);
char **sortstring(char **,int );
void write(char **,char *,int );
int main(int argc,char *argv[])
{   int numstrings=0,i;
    char **strings;
    if(argc!=3){
        fprintf(stderr,"Error in no. of argc in commandline");
        exit(EXIT_FAILURE);
    }
    strings=readfile(argv[1],&numstrings);
    strings=sortstring(strings,numstrings);
    write(strings,argv[2],numstrings);
    for(i=0;i<numstrings;i++){
        free(strings[i]);
    }
    free(strings);
    return 0;
}
char **readfile(char *name,int *numstrings){
     FILE *fp;
     char **strings;
     char word[MAXLENGTH+1];
     int i=0,n=0;
     fp=fopen(name,"r");
     if(fp==NULL){
        fprintf(stderr,"Error in opening the file!!");
        exit(EXIT_FAILURE);
     }
     while(fscanf(fp,"%s",word)!=EOF){
        i++;
     }
     n=i;
     *numstrings=n;
     fclose(fp);
     strings=(char **)malloc(n*sizeof(char *));
     if(strings==NULL){
        fprintf(stderr,"Error in allocating the memory");
        exit(EXIT_FAILURE);
     }
     fp=fopen(name,"r");
     i=0;
     while(i<n && fscanf(fp,"%s",word)!=EOF){
        strings[i]=(char *)malloc((strlen(word)+1)*sizeof(char));
         if(strings[i]==NULL){
            fprintf(stderr,"Error in allocating the memory");
            exit(EXIT_FAILURE);
         }
        strcpy(strings[i],word);
        i++;
     }
     fclose(fp);

    return strings;
}
char **sortstring(char **strings,int numstrings){
       char *ptr;
       int i=0,j=0;
       for(i=1;i<numstrings;i++){
        ptr=strings[i];
        j=i-1;
        while(j>=0 && strcmp(strings[j],ptr)>0){
            strings[j+1]=strings[j];
            j--;
        }
        strings[j+1]=ptr;
       }
       return strings;
}
void write(char **strings,char *name,int numstrings){
     FILE *fp;
     int i=0;
     fp=fopen(name,"w");
     if(fp==NULL){
        fprintf(stderr,"Error in opening the file!!");
        exit(EXIT_FAILURE);
     }
     for(i=0;i<numstrings;i++){
        fprintf(fp,"%s",strings[i]);
        fprintf(fp,"\n");
     }
     fclose(fp);

}

