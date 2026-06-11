#include<stdio.h>
long long factorial(int n){
    long long fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}
int main(){
    int num=20;
    printf("The factorial of %d is %lld",num,factorial(num));
    return 0;
}