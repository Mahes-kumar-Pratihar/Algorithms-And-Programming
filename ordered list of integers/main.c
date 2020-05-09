#include <stdio.h>
#include <stdlib.h>
typedef struct node_s node_t;
struct node_s{
    int val;
    node_t *next;
};
int main()
{
    node_t *head=NULL;
    char c;
    int stop=0,value;
    while(stop==0){
        printf("Press 'i' for inserting in list\n");
        printf("Press 's' for searching the value\n");
        printf("Press 'f' for deleting first element of list\n");
        printf("Press 'l' for deleting last element of list\n");
        printf("Press 'd' for deleting any element in list\n");
        printf("Press 'p' for printing all the elements in the list\n");
        printf("Press 'e' for stoping the program\n ");
        printf("Enter the the choice --> ");
        printf("%c",&c);
        switch(c){
            case i:value = readvalue();



        }
    }
    return 0;
}
int readvalue(){
    int val;
    printf("enter the value -->  ");
    scanf("%d",&val);
    return val;
}
node_t *insertion(node_t *head,int value){
    node_t *p,*q,*n;
    p=(node_t *)malloc(sizeof(node_t));
    if(p==NULL){
        printf("Error in allocating the memory");
        exit(EXIT_FAILURE);
        }
    p->val=value;
    p->next=NULL;
    if(head==NULL || val<head->val){
        p->next=head;
        return p;
    }
    while(q->next!=NULL && q->next->val<val){
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
    return head;
}
