#include <iostream>
using namespace std;

int arr[110];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]>arr[n-1])
            cout<<arr[i]<<endl;
    }
}
