#include<stdio.h>
int main(){
    int n,count=0;
    printf("Enter a number: ");
    scanf("%d",&n);

    int temp=n;
    while(temp>0){
        temp&=(temp-1);
        count++;
    }
    printf("Number of set bits in %d is: %d", n, count);
    return 0;

}