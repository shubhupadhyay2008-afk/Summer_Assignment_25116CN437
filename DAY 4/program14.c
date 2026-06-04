#include<stdio.h>
int main(){
    int n,t1=0,t2=1,next;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        next=t1+t2;
        t1=t2;
        t2=next;
    }
    printf("The %dth term of the Fibonacci series is %d",n,t1);
    return 0;
}