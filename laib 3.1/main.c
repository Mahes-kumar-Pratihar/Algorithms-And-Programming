#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define COL 21
#define ROW 100
int main(int argc,char *argv[])
{
    FILE *fd,*fw;
    char words[ROW][COL],line[COL];
    int i=0,count[ROW]={0},num_words=0;

    if(argc!=3){
        printf("error in command line args !!");
        exit(1);
    }

    fd=fopen(argv[1],"r");
    fw=fopen(argv[2],"r");

    if(fd==NULL || fw==NULL){
        printf("error in opening in files !!");
        exit(2);
    }

    while(fscanf(fw,"%s",words[i])!=EOF){
            i++;}
    
    
    num_words=i;
    while(fscanf(fd,"%s",line)!=EOF){
        for(i=0;i<num_words;i++)
        if(strcmp(strlwr(line),strlwr(words[i]))==0)
            count[i]++;
    }

    for(i=0;i<num_words;i++){
        printf("%s - %d occurrence(s)\n",words[i],count[i]);
    }

    fclose(fw);
    fclose(fd);
    return 0;
}
