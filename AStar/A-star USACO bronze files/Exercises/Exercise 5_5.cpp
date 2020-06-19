#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string output;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    output="symmetric";
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-i-1])
            output = "not symmetric";
    }
    cout<<output;
}
