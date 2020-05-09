#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(R,C) ((R>C)?R:C)

char **malloc2d(int,int);
char **free2d(char **,int);
void find(char *,char **,char **,int,int);
int findall(int,int ,char *,char **,char **,int ,int );

int main(int argc,char *argv[])
{
    int R,C,i=0,j;
    char **matrixin,**matrixout,*word;
    FILE *f1,*f2,*f3;
    if(argc!=4){
        fprintf(stderr,"error in number of commandline args!!\n");
        exit(EXIT_FAILURE);
    }

    f1=fopen(argv[1],"r");
    if(f1==NULL){
        fprintf(stderr,"error in opening the file\n");
        exit(EXIT_FAILURE);
    }

    if(fscanf(f1,"%d%d*c",&R,&C)==EOF){
        fprintf(stderr,"error in reading the file\n");
        exit(EXIT_FAILURE);
    }

    matrixin=malloc2d(R,C);
    matrixout=malloc2d(R,C);
    word=(char *)malloc((max(R,C)+1)*sizeof(char));

    if(word==NULL){
        fprintf(stderr,"error in allocating the memory\n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            fscanf(f1,"%c",&matrixin[i][j]);
            printf("%c",matrixin[i][j]);
        }
        fscanf(f1,"%c*c");//to skip new line '\n'
    }


    f2=fopen(argv[2],"r");
    if(f2==NULL){
        fprintf(stderr,"error in opening the file\n");
        exit(EXIT_FAILURE);
    }
    while(fscanf(f2,"%s",word)!=EOF){
        find(word,matrixin,matrixout,R,C);
    }


    f3=fopen(argv[3],"w");
    if(f3==NULL){
         fprintf(stderr,"error in opening the file\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            fprintf(f3,"%c",matrixout[i][j]);
            printf("%c",matrixout[i][j]);
        }
        fprintf(f3,"\n");
        printf("\n");
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    free(word);
    matrixin=free2d(matrixin,R);
    matrixout=free2d(matrixout,R);
    return 0;
}
char **malloc2d(int r,int c){
  char **mat;
  int i=0,j=0;
  mat=(char **)malloc(r*sizeof(char *));
  if(mat==NULL){
    fprintf(stderr,"error in allocating the memory\n");
    exit(EXIT_FAILURE);
  }
  for(i=0;i<r;i++){
    mat[i]=(char *)malloc(c*sizeof(char));
    if(mat[i]==NULL){
      fprintf(stderr,"error in allocating the memory\n");
      exit(EXIT_FAILURE);
    }
  }
  for(i=0;i<r;i++){
    for(j=0;j<c;j++)
        mat[i][j]=' ';
  }
  return mat;
}
char **free2d(char **mat,int r){
   for(int i=0;i<r;i++){
    free(mat[i]);
   }
   free(mat);
   return mat;
}
void find(char *word,char **matrixin,char **matrixout,int R,int C){
    int i,j;
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if(findall(i,j,word,matrixin,matrixout,R,C)){
               return;
            }
        }
    }
    return;
}
int findall(int row,int col,char *word,char **min,char **mout,int R,int C){
     int offset[2][8]={{0, -1, -1,  -1,  0,  1,  1,  1},
                       {1,  1,  0,  -1, -1, -1,  0,  1}};
     int r,c,flag=1,i,j;
     for(i=0;i<8;i++){
            flag=1;
        for(j=0;j<strlen(word) && flag==1;j++){
            r=row+j*offset[0][i];
            c=col+j*offset[1][i];
            if(r>=R || r<0 || c<0 || c>=C || min[r][c]!=word[j] )
               flag=0;
        }
        if(flag==1){
            for(j=0;j<strlen(word);j++){
               mout[row+j*offset[0][i]][col+j*offset[1][i]]=word[j];
            }
            return 1;
        }
     }
return 0;
}
