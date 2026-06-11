#include<stdio.h>
int findMax (int a,int b){
    return(a>b)?a:b;
}
int main(){
    int x=15,y=25;
    printf("The maximum of %d and %d is %d",x,y,findMax(x,y));
    return 0;
}


