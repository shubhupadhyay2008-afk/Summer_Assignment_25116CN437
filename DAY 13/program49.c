#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr;
    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements are: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;

}