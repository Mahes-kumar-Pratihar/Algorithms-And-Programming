#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLENGTH 100
typedef struct string_t string_r;
struct string_t{
                char *words;
                int frequency;
                string_r *next;
               };
string_r *readfile(char *);
string_r *addstring(string_r *,char *);
void writefile(string_r *,char *);
void freelist(string_r *);

int main(int argc,char *argv[])
{
    string_r *head=NULL;
    if(argc!=3){
        fprintf(stderr,"error in commandline args");
        exit(EXIT_FAILURE);
    }
    head=readfile(argv[1]);
    writefile(head,argv[2]);
    freelist(head);
    return 0;
}
string_r *readfile(char *filename1){
     FILE *fp;
     char word[MAXLENGTH+2];
     int i;
     string_r *head=NULL;
     fp=fopen(filename1,"r");
     if(fp==NULL){
        fprintf(stderr,"Error in opening the file");
        return;
     }
     while(fscanf(fp,"%s",word)!=EOF){
           for(i=0;i<strlen(word);i++){
               word[i]=tolower(word[i]);
           }
           head=addstring(head,word);
     }
     fclose(fp);
     return head;
}
string_r *addstring(string_r *head,char *word){
         string_r *p,*q;
         int flag=0;
         q=(string_r *)malloc(sizeof(string_r));
         q->words=strdup(word);
         q->next=NULL;
         if(q==NULL){
            fprintf(stderr,"Error in allocating the memory");
            exit(EXIT_FAILURE);
         }
         if(head==NULL){
            q->words=strdup(word);
            q->frequency=1;
            return q;
         }
         p=head;
         while(p!=NULL ){
            if(strcmp(p->words,word)==0)
            {
                p->frequency++;
                flag=1;
                break;
            }
            p=p->next;
         }
         if(flag==0){
            q->next=head;
            head=q;
            head->frequency=1;
         }
         return head;
}
void writefile(string_r *head,char *filename2){
     string_r *p;
     FILE *fp;
     fp=fopen(filename2,"w");
     if(fp==NULL){
        fprintf(stderr,"Error in opening the file");
        return;
     }
     p=head;
     while(p!=NULL){
           fprintf(fp,"%s %d\n",p->words,p->frequency);
           p=p->next;
     }
     fclose(fp);
}
void freelist(string_r *head){
     string_r *temp;
     while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp->words);
        free(temp);
     }
}






