//insert an element in an already sorted array so that the array remains sorted afterwards as well
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,pos=-1;
    cout<<"Enter the number of elements in the array before insertion= ";
    cin>>n;
    int a[n+1];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element to be inserted= ";
    cin>>x;
    for(int i=0;i<n;i++){
        if(a[i]>x){
            pos=i;
            break;
        }
    }
    if(pos==-1)
        a[n]=x;
    else{
        for(int i=n+1;i>pos;i--)
            a[i]=a[i-1];
        a[pos]=x;
    }
    cout<<"Now, the array is:"<<endl;
    for(int i=0;i<n+1;i++)
        cout<<a[i]<<"\t";
    
}
