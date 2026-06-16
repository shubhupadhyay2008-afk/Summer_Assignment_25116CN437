#include<stdio.h>
int main(){
    int arr[]={1,3,2,1,4,1,3};
    int n=7;
    int max_element=arr[0],max_count=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>max_count){
            max_count=count;
            max_element=arr[i];
        }
    }
    printf("Maximum frequency element:%d\n",max_element);
    return 0;
}