#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 20
typedef struct str_s str_t;
struct str_s{
str_t *next;
char *key;
};
str_t *read(char *);
str_t *insrt(str_t *,char *);
void freelist(str_t*);
int main(int argc,char *argv[])
{   str_t *head=NULL,*q;
    FILE *fp;
    fp=fopen(argv[2],"w");
    if(argc!=3){
        fprintf(stderr,"Error in commandline args");
        exit(EXIT_FAILURE);
    }
    head=read(argv[1]);
    q=head;
    while(q->next!=NULL){
        fprintf(fp,"%s\n",q->key);
        q=q->next;
    }
    freelist(head);
    return 0;
}
str_t *read(char *filename){
      FILE *fp;
      str_t *head=NULL;
      char word[MAXLENGTH+1];
      fp=fopen(filename,"r");
      if(fp==NULL){
        fprintf(stderr,"Error in opening the file");
        exit(EXIT_FAILURE);
      }
      while(fscanf(fp,"%s",word)!=EOF){
           head=insrt(head,word);
      }
      fclose(fp);
      return head;
}
str_t *insrt(str_t *head,char *word){
       str_t *p,*q=head;
       int goON=1;
       p=(str_t *)malloc(sizeof(str_t));
       p->key=strdup(word);
       p->next=NULL;
       if(head==NULL || strcmp(head->key,p->key)>0){
        p->next=head;
        return p;
       }

       while(q->next!=NULL && strcmp(q->next->key,p->key)<0){
            q=q->next;
       }
       p->next=q->next;
       q->next=p;
        return head;
}
void freelist(str_t *head){
     str_t *temp;
     while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp->key);
        free(temp);
     }
}
