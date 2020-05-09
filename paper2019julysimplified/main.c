#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char in[]="The longest ENGlISH word is: PSEUDOpseudohypoparaTHYROIDISM";
    char *out;
    int s=0;
    longestSubstring(in,&out,&s);
    for(int i=0;i<s;i++)
    printf("%c",out[i]);
    return 0;
}
void longestSubstring(char *in,char **out,int *s){
     int i,j,ini=0,fin=0,count=1,max=0,flag=1;
     char *word;
     for(i=0;i<strlen(in);){
         count=1;
         if(isupper(in[i])){
            for(j=i+1;j<strlen(in)+1 && flag==1;j++){
                if(isupper(in[j]))
                    count++;
                else{
                    flag=0;
                    if(max<count){
                       max=count;
                       ini=i;
                       fin=j;
                    }
                }
            }
         flag=1;
         }
         i+=count;
     }
     word=malloc((max+1)*sizeof(char));
     if(word==NULL){
        printf("error in allocting the memory");
        exit(EXIT_FAILURE);
     }
     for(i=ini;i<fin;i++){
         word[i-ini]=in[i];
     }
     *out=word;
     *s=max;
     return;
}
