#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 35
#define NUM 100
struct rectinfo{//why can't i declare struct inside main
                     char rectangle[5];
                     float p1,p2,p3,p4;
                     float area,perimeter;
                    }key[NUM];
void AREA_PERIMETER(struct rectinfo *key,int i);
int main(int argc,char *argv[])
{
    FILE *fr,*fa,*fp;

    char line[SIZE];
    int i=0,j=0,flag=1,num_rect=0;


    if(argc!=4){
        printf("error in command line args !!");
        exit(1);
    }

    fr=fopen(argv[1],"r");

    if(fr==NULL){
        printf("error in opening the file!!");
        exit(2);
    }
    while(fgets(line,SIZE,fr)!=NULL){
        sscanf(line,"%s" "%f" "%f",key[i].rectangle,&key[i].p1,&key[i].p2);
        for(j=0;j<i && flag==1;j++){
            if(strcmp(key[i].rectangle,key[j].rectangle)==0){
                key[j].p3=key[i].p1;
                key[j].p4=key[i].p2;
                i--;
                flag=0;
            }
        }
        flag=1;
        i++;
    }
    num_rect=i;

    for(i=0;i<=num_rect;i++)
       AREA_PERIMETER(key,i);

    fa=fopen(argv[2],"w");
    fp=fopen(argv[3],"w");

     if(fr==NULL){
        printf("error in opening the file!!");
        exit(3);
    }
      if(fr==NULL){
        printf("error in opening the file!!");
        exit(4);
    }

    for(i=0;i<num_rect;i++){
        fprintf(fa,"%s  %.2f",key[i].rectangle,key[i].area);
        fprintf(fp,"%s  %.2f",key[i].rectangle,key[i].perimeter);
        fputc('\n',fa);
        fputc('\n',fp);
        }

    fclose(fr);
    fclose(fp);
    fclose(fa);

    return 0;
}
void AREA_PERIMETER(struct rectinfo *key,int i){
       float s1=0,s2=0;
       s1=((key+i)->p1)-((key+i)->p3);
       s2=((key+i)->p2)-((key+i)->p4);
       (key+i)->area=fabs(s1*s2);
       (key+i)->perimeter=2*(fabs(s1)+fabs(s2));
        return 0;
}
        //s1=pow(pow((*(key+i).p1)-(*(key+i).p3),2),0.5); i was unable to implement this code
        //s2=pow(pow(*(key+i).p2-*(key+i).p4,2),0.5);


       //s1=pow(pow(key[i].p1-key[i].p3,2),0.5);
       //s2=pow(pow(key[i].p2-key[i].p4,2),0.5);

       //key[i].area=s1*s2;

       //key[i].perimeter=2*(s1*s2);
