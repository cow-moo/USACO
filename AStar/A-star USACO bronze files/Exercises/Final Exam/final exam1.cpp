#include <iostream>
#include <algorithm>
using namespace std;

int arr[4];
int main(){
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    sort(arr,arr+4);
    cout<<arr[0];
}
