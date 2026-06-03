#include<stdio.h>
int main(){
    int n1,n2;
    printf("Enter the two number:");
    scanf("%d %d",&n1,&n2);
    int a=n1,b=n2;
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    printf("GCD of %d and %d is %d",n1,n2,a);
    return 0;
}