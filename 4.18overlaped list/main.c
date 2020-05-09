#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct member_s member_t;
typedef struct trait_s trait_t;
struct trait_s{
                char *id;
                trait_t *next;
              };
struct member_s{
                char *name;
                char sex;
                trait_t *features;
                member_t *next;
               };
int main()
{

    return 0;
}
member_t *read(char *filename){
         char line[MAX],name[MAX],firstname[MAX],lastname[MAX],sex[2];
         member_t *member,*head=NULL;
         trait_t *feature;
         FILE *fp;
         fp=fopen(filename,"r");
         if(fp==NULL){
            fprintf(stderr,"Error in opening the file");
            exit(EXIT_FAILURE);
         }
         while(fgets(line,MAX,fp)!=NULL){
            if(line[0]=='#'){
                member=(member_t *)malloc(sizeof(member_t));
                 if(member==NULL){
                    fprintf(stderr"Error in allocating the memory");
                    exit(EXIT_FAILURE);
                }
                sscanf(line,"%s %s %s",firstname,lastname,sex);//sscanf(&line[1],"%s %s %s",firstname,lastname,sex); excluding the first character
                sprintf(name,"%s %s",firstname,lastname);
                member->name=strdup(name);
                member->features=NULL;
                member->next=head;
                head=member;
            }
            else{
                feature=(trait_t *)malloc(sizeof(trait_t));
                if(feature==NULL){
                    fprintf(stderr"Error in allocating the memory");
                    exit(EXIT_FAILURE);
                }
                sscanf(line,"#%s %s",firstname,lastname);
                sprintf(name,"%s %s",firstname,lastname);
                feature->id=strdup(name);
                feature->next=
            }
         }
}
