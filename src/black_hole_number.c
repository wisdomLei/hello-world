#include<stdio.h>
#include<math.h>

int sort(int *);
int enArraize(int,int *);
int wetherBla(int,int *);
int maxValue(int *);
int minValue(int *);

int main(){
    int value = 1000 , count = 0 ;
    printf("number\twether\tcount\n");
    for(;value <= 9999;value++){
        count = 0;
        printf("%d\t",value);
        if( wetherBla(value,&count){
            printf("yes\t%d\n",count);
        }else{
            printf("no\t%d\n",count);
        }
    }
    getchar();
    return 0;
}

int sort(int arr[]){
    int i,j,n;
    n = sizeof(arr[])/sizeof(arr[0]);
    for(j=n;j>0;j--){
        for(i=0;i<j-1;i++){
            if(a[i]>=a[i+1]){
                t = a[i];a[i] = a[i+1];a[i+1] = t;
            }
        }
    }
    return 0;
}  

int enArraize(int value;int arr[]){
    Aint i,n;
    n = sizeof(arr[])/sizeof(arr[0]); 
    for(i=0;i<n;i++){
        arr[i] = value %10;
        value = value/10;
    }
    return 0;
}

int wetherBla(int value,int *count){
    int inCount = *count;
    inCount += 1;
    int arr[4] , difference;
    enArraize(value,arr[]);
    sort(arr[]);
    difference = maxValue(arr[]) - minValue(arr[]);
    if(difference == 0||inCount > 1000){
        *count = inCount;
        return 0;
    }
    if(difference != 6174){
        *count = inCount;
        return wetherBla(difference,&count);
    }else{
        *count = inCount;
        return 1;
    }
}

int maxValue(int arr[]){
    int i,n;
    n = sizeof(arr[])/sizeof(arr[0]);
    for(i = 0;i<n;i++){
        sum = sum + a[i]*pow(10,(double)(n-i-1));
    }
    return sum;
}

int minValue(int arr[]){
    int i,n;
    n = sizeof(arr[])/sizeof(arr[0]);
    for(i = 0;i<n;i++){
        sum = sum + a[i]*pow(10,(double)i);
    }
    return sum;
}
