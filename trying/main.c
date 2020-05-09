/*

Given a string str containing only lowercase letters, write the function
void histogram (char *str);
which prints all letters belonging to str along with the frequency of their occurrence in the string.
For example if
str = "azaaabbnnccacczn",
the procedure must generate the following output
"a":5, "b":2, "c":4, "n":3, "z":2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void histogram(char *);
int main()
{
    char *c = "azaaabbnnccacczn";
    histogram(c);

}
void histogram(char *str){
     int *chars =(int *) calloc(26 ,sizeof(int));
     int co = 0,i;
     for(i = 0; i < strlen(str); i++){
        chars[str[i]-'a']++;
     }
     for(i = 0; i < 26; i++){
        if(chars[i] != 0){
             if(co > 0)
                printf(", ");
           printf("%c%c%c : %d", '"', i + 'a', '"', chars[i]);
           co = 1;
        }
     }printf(".");
}
