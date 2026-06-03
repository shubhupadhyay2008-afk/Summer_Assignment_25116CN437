#include<stdio.h>
int main(){
    int low,high,i,j,isPrime;
    printf("Enter the two numbers (intervals):");
    scanf("%d %d",&low,&high);
    printf("Prime numbers between %d and %d are:",low,high);
    for(i=low+1;i<high;i++){
        isPrime=1;
        for(j=2;j<=i/2;j++){
            if(i%j==0){
                isPrime=0;
                break;
            }
        }
        if(isPrime){
            printf("%d ",i);
        }
    }
    return 0;
}