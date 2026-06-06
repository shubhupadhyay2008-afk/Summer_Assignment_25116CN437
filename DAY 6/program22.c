#include<stdio.h>
int main(){
    long long n;
    int decimal=0,i=0,rem;
    printf("Enter a binary number: ");
    scanf("%lld",&n);
    while(n!=0){
        rem=n%10;
        decimal+=rem<<i;
        n=n/10;
        i++;
    }
    printf("Decimal: %d", decimal);
    return 0;
}