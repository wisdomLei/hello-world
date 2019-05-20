/*
  This file is a test for array element as a parament income to funtion.
  The function can printf the correct result.
  So we can use a array element as a formal parameter. 
*/

#include<stdio.h>

int function(int);

int main(void){
    int array[]={0,1,2,3};
    printf("%d\n",function(array[1]));
    return 0;
}

int function(int a){
    return a;
}