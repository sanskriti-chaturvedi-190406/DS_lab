//array without repetition
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p;
    cout<<"Enter the size of array= ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array= "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1])
            p=i;
    }
    for(int i=p;i<n-1;i++)
        a[i]=a[i+1];
    cout<<"The array without repition is:"<<endl;
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<"\t";
}