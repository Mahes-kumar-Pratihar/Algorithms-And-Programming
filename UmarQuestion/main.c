#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HW_CODE 8+2 // as \n+\0
#define LENGTH_KEYWORD 20+1
#define SW_CODE 10+2
#define MAX_LENGTH 100+2
#define MAX_SOFTWARE 50
struct software{
           char sw_code[LENGTH_KEYWORD];
           char description[MAX_LENGTH];
           char first_device_code[HW_CODE];
           int count;
    }sw[4];//We can define

struct catalog{
           char data[LENGTH_KEYWORD];
}key[5];


int main(int argc,char **argv)
{

    if(argc!=4){
        printf("No. of command line arguments are not correct !!");
        exit(1);
    }
    int i=0,flag=1,flag1=0,number_of_softwares=0;
    char filename1[LENGTH_KEYWORD],filename2[LENGTH_KEYWORD];
    char keyword[LENGTH_KEYWORD];
    char line[MAX_LENGTH];
    FILE *fp1,*fp2;


    strcpy(filename1,argv[1]);
    strcpy(keyword,argv[2]);
    strcpy(filename2,argv[3]);

    fp1=fopen(filename1,"r");
    fp2=fopen(filename2,"r");
    //for storing versions_sw.txt in structure
    while(fgets(line,MAX_LENGTH,fp2)!=NULL){
        if(flag==1){
            strcpy(sw[i].sw_code,line);
            sw[i].sw_code[10]='\0';//To remove \n character at end
            flag=0;
        }
        else{
            strcpy(sw[i].description,line);
            sw[i].count=0;
            flag=1;
            i++;
        }
    }
    number_of_softwares=i;

    //storing of softwares is done and now closing the file
    fclose(fp2);
    while(fscanf(fp1,"%s%s%s%s%s",key[0].data,key[1].data,key[2].data,key[3].data,key[4].data)!=EOF){
        flag=1;
        printf("%s %s",key[0].data,key[4].data);
        for(i=1;i<4;i++){
            if(strcmp(keyword,key[i].data)==0){
                flag1=1;
                break;
            }
        }
        for(int j=0;j<number_of_softwares;j++){
            if(flag1==1 && strcmp(key[4].data,sw[j].sw_code)==0){
               printf(" %s",sw[j].description);
               flag=0;flag1=0;
            }
            if(strcmp(key[4].data,sw[j].sw_code)==0){
               if(sw[j].count==0)
                  strcpy(sw[j].first_device_code,key[0].data);
                sw[j].count++;
            }
        }
        if(flag==1)
            printf(" Software description is not available\n");

    }
    fclose(fp1);
    printf("\nStatistics SW usage:\n");
    for(i=0;i<number_of_softwares;i++){
        if(sw[i].count==0)
            printf("%s not used by any device\n",sw[i].sw_code);
        else printf("%s used by %d devices, first device : %s\n",sw[i].sw_code,sw[i].count,sw[i].first_device_code);
    }
    return 0;
}
