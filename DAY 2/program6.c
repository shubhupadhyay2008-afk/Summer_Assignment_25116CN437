#include<stdio.h>
int main(){
    in n,reversed=0,remainder;
    printf("Enter a number:");
    scanf("%d",&n);
    while(n!=0){
        remainder=n%10;
        reversed=reversed*10+remainder;
        n/=10;
    }

    printf("Reversed number is %d",reversed);
    return 0;

}
