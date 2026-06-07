#include<stdio.h>
int reverse(int n, int rev){
    if(n==0){
        return rev;
    }
    return reverse(n/10,rev*10+(n%10))l;
}

int main(){
    int  num=1234;
    printf("Reverse of %d is %d\n",num,reverse(num,0));
    return 0;
}

