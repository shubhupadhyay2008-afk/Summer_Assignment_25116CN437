#include<stdio.h>
void printUnion(int arr1[],int n1,int arr2[],int n2){
    for(int i=0;i<n1;i++){
        printf("%d",arr1[i]);
    }
    for(int i=0;i<n2;i++){
        int j,flag=0;
        for(int j=0;j<n1;j++){
            if(arr2[i]==arr1[j]){
                {flag=1;break;}
            }
        }
        if(!flag){
            printf("%d",arr2[i]);
        }
    }
}

int main(){
    int a[]={1,2,3},b[]={2,3,4};
    printf("Union");
    printUnion(a,3,b,3);
    return 0;
}