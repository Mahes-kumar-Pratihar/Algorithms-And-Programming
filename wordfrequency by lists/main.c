#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#define N 101
typedef struct string_s string_t;
struct string_s{
       char *word;
       int count;
       string_t *next;
};
string_t *fileread(char *);
string_t *checkword(string_t *,char *);
string_t *stringsort(string_t *words,int);
void filewrite(string_t *,char *,int);
void listclean(string_t *);
int main(int argc,char **argv)
{
    string_t *head=NULL,*temp;
    string_t *words;
    int count=0,i=0;
    if(argc!=3){
        fprintf(stderr,"Error in no. of args of commandline");
        exit(EXIT_FAILURE);
    }
    head=fileread(argv[1]);
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    words=(string_t *)malloc(count*sizeof(string_t));
    temp=head;
    while(temp!=NULL && i<count){
          words[i].count=temp->count;
          words[i++].word=strdup(temp->word);
          temp=temp->next;
    }
    listclean(head);
    words=stringsort(words,count);
    filewrite(words,argv[2],count);
    return 0;
}
string_t *fileread(char *filename){
         string_t *head=NULL,*temp,*q;
         FILE *fp;
         char buffer[N];
         int i=0;
         fp=fopen(filename,"r");
         if(fp==NULL){
            fprintf(stderr,"Error in opening the file!!");
            exit(EXIT_FAILURE);
         }
         while(fscanf(fp,"%s",buffer)!=EOF){
               for(i=0;i<strlen(buffer);i++)
                   buffer[i]=tolower(buffer[i]);

               temp=(string_t *)malloc(sizeof(string_t));
               temp->word=strdup(buffer);
               q=checkword(head,buffer);
               if(q==NULL){
                      temp->count=1;
                      temp->next=head;
                      head=temp;
                   }
                else
                    q->count++;
         }
         fclose(fp);
         return head;
}
string_t *checkword(string_t *head,char *word){
         string_t *traverse=head;
         while(traverse!=NULL){
              if(strcmp(traverse->word,word)==0)
                 return traverse;
              traverse=traverse->next;
         }
         return NULL;
}
void filewrite(string_t *words,char *filename,int count){
     FILE *fp;
     int i;
     fp=fopen(filename,"w");
     if(fp==NULL){
            fprintf(stderr,"Error in opening the file!!");
            exit(EXIT_FAILURE);
         }
     for(i=0;i<count;i++){
        fprintf(fp,"%s %d\n",words[i].word,words[i].count);
     }
     for(i=0;i<count;i++)
         free(words[i].word);
     free(words);
     fclose(fp);
     return ;
}
string_t *stringsort(string_t *words,int count){
       int i=0,j;
       char temp[N];
       for(i=1;i<count;i++){
           strcpy(temp,words[i].word);
           j=i-1;
           for(;j>=0 && strcmp(words[j].word,temp)>0;j--)
                      strcpy(words[j+1].word,words[j].word);
           words[j+1].word=strdup(temp);
       }
       return words;
}
void listclean(string_t *head){
     string_t *temp=head;
     while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp->word);
        free(temp);
     }
     return;
}
