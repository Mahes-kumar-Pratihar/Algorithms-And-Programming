#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAXLENGTH 30

typedef struct{
    char name[MAXLENGTH+1];
    int code;
    int laps;
    float *times;
    float avg;
}cyclist_t;

cyclist_t *readfile(int *,int *);
void list(cyclist_t *,int );
void detailswrite(cyclist_t *,int);
void bestavg(cyclist_t *,int );

int main(int argc,char *argv)
{   char cmd[MAXLENGTH];
    int numcyclist,best;
    cyclist_t *team=readfile(&numcyclist,&best);
        printf("Command -> 'list' prints all the info about all cyclists\n");
        printf("Command -> 'details' prints all the info about the cyclist\n");
        printf("Command -> 'best' prints info about best cyclist\n");
        printf("Command -> 'stop' it stops the program\n\n");
    do{
        printf("Enter the command : ");
        scanf("%s",cmd);
        if(strcmp(cmd,"list")==0){
            list(team,numcyclist);
        }
        else if(strcmp(cmd,"details")==0){
            detailswrite(team,numcyclist);
        }
        else if(strcmp(cmd,"best")==0){
            bestavg(team,best);
        }
        else if(strcmp(cmd,"stop")==0){
            printf("Program will stop");
        }
    }while(strcmp(cmd,"stop")!=0);


    return 0;
}
cyclist_t *readfile(int *numcyclist,int *best){
     cyclist_t *team;
     FILE *fp;

     int numracer=0,i=0,j=0;
     float bestavg=INT_MAX;
     fp=fopen("data.txt","r");
     if(fp==NULL){
        printf("Error in opening the file\n ");
        exit(EXIT_FAILURE);
     }
     fscanf(fp,"%d%*c",&numracer);
     *numcyclist=numracer;
     team=(cyclist_t *)malloc(numracer*sizeof(cyclist_t));
     if(team==NULL){
        printf("Error in allocating the memory\n ");
        exit(EXIT_FAILURE);
     }
     for(i=0;i<numracer;i++){
         fscanf(fp,"%s %d %d%*c",team[i].name,&team[i].code,&team[i].laps);
        // printf("%s %d %d\n",team[i].name,team[i].code,team[i].laps);
         team[i].times=(float *)malloc((team[i].laps)*sizeof(float));
         if(team[i].times==NULL){
            printf("Error in allocating the memory \n");
            exit(EXIT_FAILURE);
         }
         for(j=0;j<team[i].laps;j++){
            fscanf(fp,"%f",&team[i].times[j]);
         //   printf("%f",team[i].times[j]);
            team[i].avg =team[i].avg + team[i].times[j];
        }
         team[i].avg/=team[i].laps;
       //   printf("\n%.2f",team[i].avg);
         if(team[i].avg<bestavg){
            bestavg=team[i].avg;
            *best=i;
         }
     }
     fclose(fp);
  return team;
}
void list(cyclist_t *team,int numcyclist){
    int i=0;
    printf("Name Code Laps\n");
    for(i=0;i<numcyclist;i++){
        printf("%s %d %d\n",team[i].name,team[i].code,team[i].laps);
    }
}
void detailswrite(cyclist_t *team,int numcyclist){
     char name[MAXLENGTH+1];
     int i=0,j=0;
     printf("Enter the name of cyclist to know their details : %s",name);
     scanf("%s",name);
     for(i=0;i<numcyclist;i++){
        if(strcmp(name,team[i].name)==0){
            printf("Code -> %d\n",team[i].code);
            printf("No. of laps : %d \n",team[i].laps);
            for(j=0;j<team[i].laps;j++){
                printf("  %.2f",team[i].times[j]);
            }
            break;
        }
     }
     printf("\n");
}
void bestavg(cyclist_t *team,int best){
     printf("Name -> %s Code -> %d Laps -> %d Times -> ",team[best].name,team[best].code,team[best].laps);
     int i=0;
     for(i=0;i<team[best].laps;i++){
        printf("%.2f ",team[best].times[i]);
     }
     printf("%.2f\n",team[best].avg);
}



