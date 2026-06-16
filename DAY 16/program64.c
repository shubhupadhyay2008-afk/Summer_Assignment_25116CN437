#include<stdio.h>
int main(){
    int arr[]={!,2,2,3,4,4,5};
    int n=7,j=0;
    for(int i=0;i<n;i++){
        int is_duplicate=0;
        for(int k=0;k<j;k++){
            if(arr[i]==arr[k]){
                is_duplicate=1;
                break;
            }
        }
        if(!is_duplicate){
            arr[j++]=arr[i];
        }
    }
    printf("Array after removing duplicates:");
    for(int i=0;i<j;i++){
        printf("%d",arr[i]);
    }
    return 0;
}