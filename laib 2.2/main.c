#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE1 20
#define SIZE2 50+1
int main(int argc,char *argv[])
{
    char name[SIZE1],line[SIZE2];
    int row=0,i,j,h_count=0,v_count=0,h_found=0,countv[SIZE2];/*taking new array countv[SIZE2] for vertical as we there can max 100
                                                                characters then there can be 100 vertical sequences then just used count */
    FILE *fr;
    if(argc!=2){
        printf("error in the command line args !!");
        exit(1);
    }
    for(i=0;i<SIZE2;i++)
        countv[i]=0;
    fr=fopen(argv[1],"r");
    while(fgets(line,SIZE2,fr)!=NULL){
        for(j=0;j<strlen(line);j++){
            if(line[j]=='h')
                h_count++;
            else
                h_count=0;
            if(h_count==5){
                h_found++;
                h_count=0;}
            if(line[j]=='v')
                countv[j]++;
            else
                countv[j]=0;
            if(countv[j]==5){
                v_count++;
                countv[j]=0;}
        }

    }

    fclose(fr);
    printf("Number of horizontal sequences is : %d",h_found);
    printf("\nNumber of vertical sequences is : %d",v_count);
    return 0;
}
