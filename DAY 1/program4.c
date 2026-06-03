#include<stdio.h>
int main(){
    long long n;
    int count=0;
    printf("Enter a integer:");
    scanf("%lld",&n);

    if (n==0){
        printf("Number of digits in %lld is 1",n);
    }
    else{
        while(n!=0){
            n/=10;
            count++;
        }
    }
    
    printf("Number of digits in %lld is %d",n,count);
    return 0;
    
}
