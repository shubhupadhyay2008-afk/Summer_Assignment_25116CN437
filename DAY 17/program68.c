#include<stdio.h>
void findCommon(int a[],int b[],int n,int m){
    printf("Common elements are:");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                printf("%d",a[i]);
                break;
            }
        }
    }
}

int main(){
    int a[]={10,20,30,40,50};
    int b[]={15,20,35,40,45};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    findCommon(a,b,n,m);
    return 0;
}