#include<stdio.h>
int main(){
    int arr[]={1,4,6,8,10};
    int target=14,n=5;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                printf("Pair found:(%d,%d)\n",arr[i],arr[j]);
            }
        }
    }
    return 0;
}