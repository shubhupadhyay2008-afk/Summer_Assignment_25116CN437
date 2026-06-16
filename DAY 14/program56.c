#include<stdio.h>
int main(){
    int arr[]={4,2,4,5,2,3,1},n=7;
    printf("Duplicate elements in the array are: ");
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                printf("%d ",arr[i]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
