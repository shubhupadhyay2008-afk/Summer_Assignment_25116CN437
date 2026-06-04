#include<stdio.h>
#include<math.h>
int main(){
    int low,high,i,temp1,temp2,remainder,n=0;
    float result=0.0;
    printf("Enter the lower and upper limit:");
    scanf("%d %d",&low,&high);
    printf("Armstrong numbers between %d and %d are:",low,high);
    for(i=low+1;i<high;i++){
        temp1=i;
        temp2=i;
        n=0;
        result=0;
        while(temp1!=0){
            temp1/=10;
            n++;
        }
        while(temp2!=0){
            remainder=temp2%10;
            result+=pow(remainder,n);
            temp2/=10;
        }
        if((int)result==i)printf("%d ",i);
        
    }
    return 0;
}