#include<stdio.h>
#include<limits.h>
int main(){
    int arr[]={12,35,1,10,34,1},n=6;
    int first=INT_MIN,second=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>first){
            second=first;
            first=arr[i];
        }
        else if(arr[i]>second && arr[i]!=first){
            second=arr[i];
        }
    }
    printf("First largest element: %d\n", first);
    printf("Second largest element: %d\n", second);
    return 0;
}