#include <stdio.h>
#include <stdlib.h>
#define DIM1 5
#define DIM2 3
int main()
{
    char m1[DIM1][DIM1]={
                         "*#**#",
                         "###**",
                         "*#*#*",
                         "#*###",
                         "#**#*"
                        };
    char m2[DIM2][DIM2]={"*#*","###","*#*"};
    char tmtx[DIM1][DIM1]={0};
    int i,j,r,c,flag=1;
    for(i=0;i<DIM1;i++){
        for(j=0;j<DIM1;j++){
           tmtx[i][j]='0';
        }
    }

    for(i=0;i<=DIM1-DIM2;i++){
            for(j=0;j<=DIM1-DIM2;j++){
                flag=1;
                for(r=0;r<DIM2 && flag==1;r++){
                    for(c=0;c<DIM2 && flag==1;c++){
                        if(m1[i+r][j+c]!=m2[r][c]){
                            flag=0;
                        }
                    }
                }

            if(flag==1){
                for(r=0;r<DIM2;r++){
                    for(c=0;c<DIM2;c++){
                        tmtx[r+i][c+j]=m2[r][c];
                    }
                }
            }
            }

    }
    for(i=0;i<DIM1;i++){
        for(j=0;j<DIM1;j++){
            printf("%c",tmtx[i][j]!='0' ? tmtx[i][j] : ' ' );
        }
        printf("\n");
    }
     return 0;
}
