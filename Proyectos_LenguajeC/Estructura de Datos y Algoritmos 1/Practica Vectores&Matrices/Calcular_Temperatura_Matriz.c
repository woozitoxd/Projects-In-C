
#include <stdio.h>

int main(){
    float resultado[3][4],max,min,max_D[3],min_D[3];
    int flag=0,flag2=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("\nIngrese la temperatura: ");
            scanf("%f",&resultado[i][j]);
            if(flag == 0){
                max = resultado[i][j];
                min = resultado[i][j];
                flag = 1;
            }
            if(max < resultado[i][j]){
                max = resultado[i][j];
            }
            if(min > resultado[i][j]){
                min = resultado[i][j];
            }
        }
        max_D[i] = max;
        min_D[i] = min;
        flag=0;
    }


for(int i=0;i<3;i++){
        printf("\n");
        for(int j=0;j<4;j++){
            printf("- %.1f -",resultado[i][j]);
        }
    }
    printf("\nMaxima de la semana es %.1f -\n",max);
    printf("\nMinima de la semana es %.1f -",min);
return 0;
}
