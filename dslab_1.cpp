//insertion
#include <iostream>
using namespace std;

int main(){
    int x,p,n;
    cout<<"Enter the size of array= ";
    cin>>n;
    int ar[n+1];
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    cout<<"Enter the value to be inserted and its position:\n";
    cin>>x>>p;
    //cout<<endl;
    for(int i=n-1;i>=p;i--)
        ar[i+1]=ar[i];
    ar[p]=x;
    cout<<"Now, the elements of array are:"<<endl;  
    // for(int a:ar)
    //     cout<<a<<endl
    //this will read the zeroes at the empty location in the array as well.
    for(int i=0;i<n+1;i++)
        cout<<ar[i]<<"\t";
    return 0;
}
//Write the code for deletion as well.