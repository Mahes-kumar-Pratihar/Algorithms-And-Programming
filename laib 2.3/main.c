#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 102
#define STRLEN 22
int main(int argc,char *argv[STRLEN])
{
    int k=0,i=0,flag=0,count=0;
    char line[SIZE],string1[STRLEN],string2[STRLEN],str[SIZE];

    FILE *fr,*fw;
    if(argc!=5){
        printf("Error in the command line args !!");
        return -1;
    }
    fr=fopen(argv[2],"r");
    fw=fopen(argv[4],"w");
    strcpy(string1,argv[1]);
    strcpy(string2,argv[3]);

    while(fgets(line,SIZE,fr)!=NULL){
        for(int i=0;i<strlen(line)-4*count;i++){
            if(line[i]=='t'){
                    flag=1;
                for(k=1;k<strlen(string1) && flag==1;k++){
                     if(line[i+k]!=string1[k])
                        flag=0;/*checking if the found t makes the desire word*/
                }
              }
            if(flag==1)
                {fputs(string2,fw);
                 i=i+3;
                 printf("%s",string2);}
            else
                {fputc(line[i],fw);
                printf("%c",line[i]);
                }
           flag=0;
        }
    count=0;
    }
    fclose(fr);
    fclose(fw);
    return 0;
}
