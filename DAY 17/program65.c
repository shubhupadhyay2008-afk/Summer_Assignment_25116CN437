#include<stdio.h>
int main(){
    int a[]={1,2,3},b[]={4,5,6};
    int n1=3,n2=3,res[6];
    for(int i=0;i<n1;i++){
        res[i]=a[i];
    }
    for(int i=0;i<n2;i++){
        res[n1+i]=b[i];
    }
    printf("Merged:");
    for(int i=0;i<n1+n2;i++){
        printf("%d",res[i]);
    }
    return 0;

}