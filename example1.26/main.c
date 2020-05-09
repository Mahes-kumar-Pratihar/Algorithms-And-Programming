#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXFLIGHTS 20

typedef struct{
        char code[6];
        char depcity[21];
        char arricity[21];
        float deptime,arritime;
}flight_t;

int readflights(flight_t *flight,char *filename);
void connections(flight_t *flight,int nf,flight_t request);
void info(flight_t flight);

int main(int argc,char *argv[])
{   flight_t FLIGHTS[MAXFLIGHTS];
    flight_t request;
    int nf=0;
    nf=readflights(FLIGHTS,argv[1]);

    printf("Enter the name of departure city :  ");
    scanf("%s",request.depcity);
    printf("\nEnter the name of arrival city :  ");
    scanf("%s",request.arricity);
    printf("\nEnter the departure time :  ");
    scanf("%f",&request.deptime);
    connections(FLIGHTS,nf,request);
    return 0;
}
int readflights(flight_t *flight,char *filename){

    FILE *fp;
    char line[100];
    int i=0;
    fp=fopen(filename,"r");
    if(fp==NULL){
        fprintf(stderr,"error in opening the file !!");
        exit(EXIT_FAILURE);
    }

    while(fgets(line,100,fp)!=NULL && i<MAXFLIGHTS){
          sscanf(line,"%s%s%s%f%f",flight[i].code,flight[i].depcity,flight[i].arricity,&flight[i].deptime,&flight[i].arritime);
          i++;
    }
    fclose(fp);
    return i;
}
void connections(flight_t *flight,int nf,flight_t request){
     int i=0,j=0;
     //for non stop flights
     for(i=0;i<nf;i++){
        if((strcmp(flight[i].depcity,request.depcity)==0) && flight[i].deptime>=request.deptime){
            if((strcmp(flight[i].arricity,request.arricity)==0)){
               printf("\nNo stop :");
               info(flight[i]);
            }
        }
     }
     //for single stop flights
     for(i=0;i<nf;i++){
            if((strcmp(flight[i].depcity,request.depcity)==0) && flight[i].deptime>=request.deptime)
                  for(j=0;j<nf;j++){
                      if((strcmp(flight[j].depcity,flight[i].arricity)==0)&& (strcmp(flight[j].arricity,request.arricity)==0) &&
                          flight[j].deptime>=flight[i].arritime){
                          printf("\n1 stop :");
                          info(flight[i]);
                          info(flight[j]);

                      }
                  }
     }

}

void info(flight_t flight){
     printf("\n\t%s ",flight.code);
     printf("%s %s ",flight.depcity,flight.arricity);
     printf("%2.2f %2.2f",flight.deptime,flight.arritime);
}


