#include<stdio.h>
int main(){
    int arr[]={1,2,4,5,6};
    int n=6;
    int expected_sum=n*(n+1)/2;
    int actual_sum=0;
    for(int i=0;i<n-1;i++){
        actual_sum+=arr[i];
    }
    printf("Missing number:%d\n",expected_sum-actual_sum);
    return 0;
}