#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

void bubble(int length,int x[1000]){
    for(int j=length-1;j>=0;j--){
        for(int i=0;i<j;i++){
            if(x[i]>x[i+1])
                swap(x[i],x[i+1]);
        }
    }
}

int arr[1000];
int main(){
    freopen("sortingstuff.in","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bubble(n,arr);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
