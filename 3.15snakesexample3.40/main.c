#include <stdio.h>
#include <stdlib.h>

char **malloc2d(int ,int );
int *minmaxlensearch(int *length,int num);
char **free2d(char **,int);
int main(int argc,char *argv[])
{   FILE *fp;
    char **map,c;
    int *length;
    int offset[2][8]={{0,-1,-1, -1, 0, 1, 1, 1},
                      {1, 1, 0, -1,-1,-1, 0, 1}};
    int R,C,i,j,numsnakes=0,row,col,k,l,len=0;
    if(argc!=2){
        fprintf(stderr,"error in opening the file");
            exit(EXIT_FAILURE);
    }
    fp=fopen(argv[1],"r");
    fscanf(fp,"%d%d",&R,&C);
    fscanf(fp,"%c",&c);
    map=malloc2d(R,C);

    length=malloc((R+C)*sizeof(int));
    for(i=0;i<R+C;i++){
        length[i]=0;
    }
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            fscanf(fp,"%c",&map[i][j]);
            printf("%c",map[i][j]);
        }
        fscanf(fp,"%c",&c);
        printf("%c",c);
    }
    fclose(fp);
    int flag=1,rw,cl,flag2;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if(map[i][j]=='+'){
                    numsnakes++;
                    row=i;
                    col=j;
                    flag2=1;
                for(k=0;k<R+C && flag2==1;k++){
                    for(l=0;l<8 && flag==1;l++){
                        rw=row+offset[0][l];
                        cl=col+offset[1][l];
                        if(rw>=0 && rw<R && cl>=0 && cl<C)
                        if(map[rw][cl]=='*'){
                            map[row][col]='.';
                            length[len]++;
                            flag=0;
                            row=rw;
                            col=cl;
                        }
                    }
                    if(flag==1){
                        flag2=0;
                        length[len]++;
                         printf("Snake (%d,%d) has length -> %d\n",i,j,length[len]);
                    }
                flag=1;
                }
            len++;
            }
        }
    }
    printf("Number of snakes -> %d",numsnakes);
    length=minmaxlensearch(length,len);
    printf("\nSnake of min length is -> %d\nSnake of max length is -> %d",length[0],length[len-1]);
    map=free2d(map,R);
    free(length);
    return 0;
}

char **malloc2d(int R,int C){
        int i;
        char **map;
        map=(char **)malloc(R*sizeof(char *));
        if(map==NULL){
            fprintf(stderr,"error in allocating the memory");
            exit(EXIT_FAILURE);
        }
        for(i=0;i<R;i++){
            map[i]=(char *)malloc(C*sizeof(char));
            if(map[i]==NULL){
               fprintf(stderr,"error in allocating the memory");
               exit(EXIT_FAILURE);
            }
        }
return map;
}
int *minmaxlensearch(int *length,int num){
    int i,j,x;
    for (i=1; i<num; i++) {
       x = length[i];
       for(j =i-1;j>=0 && x<length[j];j--)
           length[j+1]=length[j];
       length[j+1] = x;
   }

return length;
}
char **free2d(char **map,int R){
     int i=0;
     for(i=0;i<R;i++){
        free(map[i]);
     }
     free(map);

     return map;
}






