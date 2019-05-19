/*
  This file is a test for array element as a parament income to funtion.
*/

#include<stdio.h>

int main(void){
    int array[]={0,1,2,3};
    printf("%d\n",fuction(array[1]));
    return 0;
}

int function(int a){
    return a;
}