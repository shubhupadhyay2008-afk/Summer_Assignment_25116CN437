#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the size:");
    scanf("%d",&n);
    int arr;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("The sum of the elements is: %d",sum);
    printf("\nThe average of the elements is: %f",sum/n);
    return 0;

}