/*
    The reason of this file is to test a 2D array as a para income a function.
*/
#include <stdio.h>
#define M 3
#define N 3

int function(float x[M][N]);

int main(void){
    int i,j;
    float x[M][N];
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            x[i][j] = 0;
        }
    }
    function(x);
    return 0;
}

int function(float x[M][N]){
    printf("%f\n",x[0][0]);
    return 0;
}