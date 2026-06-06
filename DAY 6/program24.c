#include<stdio.h>
int main(){
    double base,result=1.0;
    int exponent;
    printf("Enter base(x) and exponent(n): ");
    scanf("%lf %d",&base,&exponent);
    for(int i=0;i<exponent;i++){
        result*=base;
    }
    printf("%.2lf^%d = %.2lf", base, exponent, result);
    return 0;
}