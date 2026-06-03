#include<stdio.h>
int main(){
    unsigned long long fact=1;
    printf("Enter a number:");
    scanf("%d",&n);
    if(n<0){
        printf("Error!Factorial of a negative number doesn't exists");
    }
    else{
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        printf("Factorial of %d=&llu",n,fact);
    }

    return 0;

        

}