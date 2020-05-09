#include "file.h"
char *characters(char *str,char *string,int *num){
     int i=0,j=0,flag,n=*num;
     for(i=0;i<strlen(string);i++){
            flag=1;
        for(j=0;j<n && flag==1;j++){
            if(string[i]==str[j])
                flag=0;
        }
        if(flag==1){
            str[n]=string[i];
            n++;
        }
     }
     *num=n;
     return str;
}
void user_input(char *str,char *str1,char *str2,char *str3,int letter_used){
     int i;
     int *arr=malloc(letter_used*sizeof(int));
     for(i=0;i<letter_used;i++){
        printf("\n\t>>Provide input for '%c' --> ",str[i]);
        fscanf(stdin,"%d",&arr[i]);
     }
     if(solution_check(str,str1,str2,str3,arr,letter_used)){
        fprintf(stdout,"\n\n\t\t>>>Correct solution !! Brravo");
     }
     else
        printf("Incorrect solution! try again");
     free(arr);
}
int solution_check(char *str,char *str1,char *str2,char *str3,int *arr,int letter_used){
    int z,x,y;
    x=char_to_num(str,str1,arr,letter_used);
    y=char_to_num(str,str2,arr,letter_used);
    z=char_to_num(str,str3,arr,letter_used);
    if(z==(x+y))
        return 1;
    else
        return 0;
}
int char_to_num(char *str,char *string,int *arr,int letter_used){
    int i,j,num=0;
    for(i=0;i<letter_used;i++)
        if(string[0]==str[i] && arr[i]==0)
            return -1;
    for(i=0;i<strlen(string);i++){
        for(j=0;j<letter_used;j++){
            if(string[i]==str[j]){
                num=num*10+arr[j];
            }
        }
    }
    return num;
}
void solve(char *str,char *str1,char *str2,char *str3,int letter_used){
           int nums[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
           int *sol =  malloc(letter_used*sizeof(int));
           int taken[N-1]={0};
           if(!solution_find_r(nums,sol,taken,letter_used,0,str,str1,str2,str3,0))
              printf("\n\n\n\t\tSORRY NO SOLUTION!! try different strings");
           free(sol);
           return;
}
int solution_find_r(int nums[],int *sol,int taken[],int letter_used,int pos,char *str,char *str1,char *str2,char *str3,int count){
     int i;
     if(pos>=letter_used){
        if(solution_check(str,str1,str2,str3,sol,letter_used)){
                printf("\tSolution : \n");
            for(i=0;i<letter_used;i++){
                printf("\t%c -> %d\n",str[i],sol[i]);
            }
           return count+1;
        }
        return count;
     }
     for(i = 0;i<10;i++){
        if(taken[i]==0){
            taken[i]=1;
            sol[pos]=nums[i];
            count=solution_find_r(nums,sol,taken,letter_used,pos+1,str,str1,str2,str3,count);
            taken[i]=0;
        }
     }
     return count;
}

