//HW: Write the code for deletion as well.
#include <iostream>
using namespace std;

int main(){
    int p,n;
    cout<<"Enter the size of array= ";
    cin>>n;
    int ar[n];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<"Enter the position of the value to be deleted:\n";
    cin>>p;
    for(int i=p;i<=n-2;i++) 
        ar[i]=ar[i+1];
    cout<<"Now, the elements of array are:"<<endl;  
    for(int i=0;i<n-1;i++)
        cout<<ar[i]<<"\t";
    return 0;
}