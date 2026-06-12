#include<stdio.h>
void checkArmstrong(int n){
    int sum=0,remainder,original=n;
    while(n!=0){
        remainder=n%10;
        sum+=remainder*remainder*remainder;
        n/=10;
    }
    if(original==sum){
        printf("%d is an Armstrong number.",original);
    }
    else{
        printf("%d is not an Armstrong number.",original);
    }
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    checkArmstrong(num);
    return 0;
}