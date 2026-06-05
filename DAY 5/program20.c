#include<stdio.h>
itn main(){
    long long n,maxPrime=-1;
    printf("Enter a number:");
    scanf("%lld",&n);
    while (n%2==0){
        maxPrime=2;
        n/=2;
    }
    for (int i=3;i*i<=n;i+=2){
        while (n%i==0){
            maxPrime=i;
            n/=i;
        }
    }
    if (n>2){
        maxPrime=n;
    }
    printf("The largest prime factor of the given number is: %lld",maxPrime);
    return 0;
    

}
