#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40+1
int main(int argc,char **argv)
{
    char str1[MAX],str2[MAX],str3[MAX];
    if(argc!=4){
        fprintf(stderr,"Error in commandline args!");
        return -1;
    }
    strcpy(str1,argv[1]);
    strcpy(str2,argv[2]);
    strcpy(str3,argv[3]);
    int i=0,j=0,flag=1;
    for(i=0;i<strlen(str1);){
        if(str1[i]!=str2[0]){
            printf("%c",str1[i]);
            i++;}
        else{
            flag=1;
            for(j=1;j<strlen(str2) && flag==1;j++){
                if(str1[j+i]!=str2[j])
                    flag=0;
            }
            if(flag==1){
                printf("%s",str3);
                i+=strlen(str2);
            }
            else
                i++;
        }
    }
    return 0;
}
