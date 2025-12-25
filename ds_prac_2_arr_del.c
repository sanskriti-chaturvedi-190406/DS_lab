#include<stdio.h>
int main(){
    int n,pos;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[100];
    for(int i=0;i<n;i++){
        printf("Enter element %d\n",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the position to be deleted:\n");
    scanf("%d",&pos);
    if(pos<1 || pos>n){
        printf("Invalid position\n");
        return 0;
    }
    else{
        for(int i=pos-1;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        n--;
        printf("Array after deletion:\n");
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    return 0;
}