#include<stdio.h>
int main(){
    int arr[]={1,2,2,3,2,4,5},n=7,target,count=0;
    printf("Enter the target element: ");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            count++;
        }
    }
    printf("Frequency of %d in the array is: %d\n",target,count);
    return 0;
}