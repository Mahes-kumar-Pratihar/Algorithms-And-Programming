#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 100

/* Version A
  It stores words in an 1D dynamic array of structures including
  a dynamically allocated string:*/

typedef struct str_s{
    char *str;
  }str_t;
str_t *readfile(char *,int *);
str_t *sortstring(str_t *,int );
void writefile(char *,str_t *,int);
int main(int argc,char *argv[])
{
    str_t *words;
    int n;
    if(argc!=3){
        fprintf(stderr,"Error in commandline args");
        exit(EXIT_FAILURE);
    }
    words=readfile(argv[1],&n);
    words=sortstring(words,n);
    writefile(argv[2],words,n);
    return 0;
}
str_t *readfile(char *filename,int *num){
      FILE *fp;
      str_t *words;
      char word[MAXLENGTH+1];
      int n,i=0;
      fp=fopen(filename,"r");
      if(fp==NULL){
        fprintf(stderr,"Error in opening the file");
        exit(EXIT_FAILURE);
      }
      fscanf(fp,"%d%*c",&n);
      *num=n;
      words=(str_t *)malloc(n*sizeof(str_t));
      if(words==NULL){
        fprintf(stderr,"Error in allocating the memory");
        exit(EXIT_FAILURE);
      }
      while(i<n && fscanf(fp,"%s",word)!=EOF){
        words[i].str=(char *)malloc((strlen(word)+2)*sizeof(char));
        strcpy(words[i].str,word);
        i++;
      }
      fclose(fp);
return words;
}
str_t *sortstring(str_t *words,int n){
     int i,j;
     char *ptr;
     for(i=1;i<n;i++){
        ptr=words[i].str;
        j=i-1;
        while(j>=0 && strcmp(ptr,words[j].str)<0){
            words[j+1].str=words[j].str;
            --j;
        }
       words[j+1].str=ptr;
     }


return words;
}
void writefile(char *filename,str_t *words,int n){
     FILE *fp;
     int i;
     fp=fopen(filename,"w");
     if(fp==NULL){
        fprintf(stderr,"Error in opening the file");
        exit(EXIT_FAILURE);
      }
     i=0;
     while(i<n){
        fprintf(fp,"%s\n",words[i].str);
        //fputc('\n',fp);
        ++i;
     }
     fclose(fp);
}
