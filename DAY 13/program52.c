#include<stdio.h>
int main(){
    int n,i,even=0,odd=0;
    printf("Enter the size:");
    scanf("%d",&n);
    int arr;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Even and odd elements are: %d and %d",even,odd);
    return 0;
}