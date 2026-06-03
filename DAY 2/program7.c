#include<stdio.h>
int main(){
    int n,product=1,digit;
    printf("Enter a number:");
    scanf("%d",&n);
    if(n==0){
        printf("Product of digits in %d is 0",n);
    }
    
     while(n!=0){
            digit=n%10;
            product*=digit;
            n/=10;
    }

    printf("Product of digits in %d is %d",n,product);
    return 0;
 }
    
    
