#include<stdio.h>
int main(){
    int num,originalNum,rem,sum=0;
    printf("Enter a number:");
    scanf("%d",&num);
    originalNum=num;
    while(num>0){
        rem=num%10;
        int fact=1;
        for (int i=1;i<=rem;i++){
            fact*=i;
        }
        sum+=fact;
        num/=10;
    }
    if (sum==originalNum){
        printf("%d is a strong number.",originalNum);
    }
    else{
        printf("%d is not a strong number.",originalNum);
    }
    return 0;
}