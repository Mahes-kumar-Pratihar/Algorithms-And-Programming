#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc,char *argv[])
{
    FILE *fr,*fw;
    char c;
    int count=0,flag=0;
    if(argc!=3){
        fprintf(stderr,"error in number of commandline args !!");
        exit(EXIT_FAILURE);
    }
    fr = fopen(argv[1],"r");
    if(fr==NULL){
        fprintf(stderr,"error in opening the file !!");
        exit(EXIT_FAILURE);
    }
    fw = fopen(argv[2],"w");
    if(fw==NULL){
        fprintf(stderr,"error in opening the file !!");
        exit(EXIT_FAILURE);
    }

    while(fscanf(fr,"%c",&c)!=EOF){
        if(c!='\n'){
            if(count==20){
               fprintf(fw,"\n");
               printf("\n");
               count=0;
            }
            if(c==' '){
               flag=1;
            }
            else { if(flag==1){
                    flag=0;
                    c=toupper(c);
                   }

                  fprintf(fw,"%c",c);
                  printf("%c",c);
                  count++;
            }



        }
    }
    fclose(fr);
    fclose(fw);
    return 0;
}
