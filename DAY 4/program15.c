#include<stdio.h>
#include<math.h>
int main(){
    int num,original,remainder,n=0;
    float result=0.0;
    printf("Enter an integer:");
    scanf("%d",&num);
    original=num;
    for(original=num;original!=0;n++)original/=10;
    original=num;
    while(original!=0){
        remainder=original%10;
        result+=pow(remainder,n);
        original/=10;
    }
    if((int)result==num)printf("%d is an Armstrong number.",num);
    else printf("%d is not an Armstrong number.",num);
    return 0;
}