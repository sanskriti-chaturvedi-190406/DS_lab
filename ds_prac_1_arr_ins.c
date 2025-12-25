#include <stdio.h>
int main(){
int n;
printf("Enter the size of the array\n");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
printf("Enter element %d\n",i+1);
scanf("%d",&arr[i]);
}
printf("Array elements are:");
for(int i=0;i<n;i++){
printf("%d ",arr[i]);
}
return 0;
}
