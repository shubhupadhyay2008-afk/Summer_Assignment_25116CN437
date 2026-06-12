#include<stdio.h>
void checkPerfect(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n){
        printf("%d is a Perfect number.",n);
    }
    else{
        printf("%d is not a Perfect number.",n);
    }
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    checkPerfect(num);
    return 0;
}