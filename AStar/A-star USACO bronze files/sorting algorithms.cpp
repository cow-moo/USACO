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
void selection(int length,int x[1000]){
    int minimum=length-1;
    for(int i=0;i<length;i++){
        for(int j=i;j<length;j++){
            if(x[j]<x[minimum])
                minimum = j;
        }
        swap(x[i],x[minimum]);
        minimum = length-1;
    }
}

int arr[1000];
int main(){
    freopen("sortingstuff.in","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    selection(n,arr);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
