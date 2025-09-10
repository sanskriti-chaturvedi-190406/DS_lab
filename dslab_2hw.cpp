//HW:merge two sorted arrays to create another sorted array 

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2;
    cout<<"Enter the no. of elements in sorted array 1= ";
    cin>>n1;
    int a[n1];
    for(int i=0;i<n1;i++)
        cin>>a[i];
    cout<<"Enter the no. of elements in sorted array 2= ";
    cin>>n2;
    int b[n2];
    for(int i=0;i<n2;i++)
        cin>>b[i];
    int A[n1+n2];
    int l=0,r=0,k=0;
    while(l<n1&&r<n1){
        if(a[l]<b[r]){
            A[k]=a[l];
            l++;
            k++;
        }
        else{
            A[k]=b[r];
            r++;
            k++;
        }
    }
    while(l<n1){
        A[k]=a[l];
        l++;
        k++;
    }
    while(r<n2){
        A[k]=b[r];
        r++;
        k++;
    }
    cout<<"The resulting sorted array is: ";
    for(int a:A)
         cout<<a<<"\t";
}