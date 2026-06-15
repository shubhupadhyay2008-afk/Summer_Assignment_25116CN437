#include<stdio.h>
int main(){
    int arr[]={0,1,0,3,12};
    int n=5;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            int temp=arr[count];
            arr[count]=arr[i];
            arr[i]=temp;
            count++
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;e
}