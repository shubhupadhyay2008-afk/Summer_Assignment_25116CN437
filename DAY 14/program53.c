#include<stdio.h>
int main(){
    int arr[]={10,25,30,45,50},n=5,target,found=-1;
    printf("Enter the target element: ");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            found=i;
            break;
        }
    }
    if(found!=-1){
        printf("Element found at index: %d\n",found);
    }
    else{
        printf("Element not found in the array.\n");
    }
    return 0;
}