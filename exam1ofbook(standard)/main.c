#include "file.h"
int main(int argc,char **argv)
{
    if(argc!=4){
        fprintf(stderr,"Error in commandline args!");
        return -1;
    }
    int num=0,choice=-1;
    char str1[M],str2[M],str3[M];
    char *str=malloc(N*sizeof(char));
    /*strcpy(str1,argv[1]);
    strcpy(str2,argv[2]);
    strcpy(str3,argv[3]);*/

    while(choice!=0){
        printf("\n\n\t>>Enter first string -> ");
        scanf("%s",str1);
        printf("\t>>Enter second string -> ");
        scanf("%s",str2);
        printf("\t>>Enter third string -> ");
        scanf("%s",str3);
        str=characters(str,str1,&num);
        str=characters(str,str2,&num);
        str=characters(str,str3,&num);
        /*for(int i=0;i<num;i++) to show different chars from all three strings
        printf("%c",str[i]);*/
        if(num>N-1){
            printf("\n>>Opps! provided strings are combination of more than 10 different characters");
            choice=3;
        }
        else{
            if(choice==1 || choice==2 || choice!=0)
               printf("\n\n\t>>Enter '1' for providing the input\n\t>>Enter '2' for getting answer");
               printf("\n\t>>Enter '0' for quiting the program\n\t>>Enter you choice -> ");
            scanf("%d",&choice);
            }

        switch(choice){
           case 1:user_input(str,str1,str2,str3,num);
                  fprintf(stdout,"\n\n\t>>Press '1' to try again and press '0' to quit -> ");
                  scanf("%d",&choice);
                  break;
           case 2:solve(str,str1,str2,str3,num);
                  printf("\n\n\t>>For quiting the program press '0' and to continue press '1' -> ");
                  scanf("%d",&choice);
                  break;
           case 3:printf("\n\n\t>>For quiting the program press '0' and to continue press '1' -> ");
                  scanf("%d",&choice);
                  break;
           default:
                   if(choice==0){
                      printf(">>You chose to end the program\n");
                      break;
                   }
                   else{
                    printf("\n>>Ivalid operation!!!\n\n\tTRY AGAIN and press '2' if you want my solution");
                    break;
                   }
        }
     }

    return 0;
}
