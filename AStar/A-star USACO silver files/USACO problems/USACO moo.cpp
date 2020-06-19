#include <iostream>
using namespace std;

int n,initk=0,sarray[100];

void maxk(){
    int length=3;
    while(length<=n){
        initk++;
        length=2*length+initk+3;
        sarray[initk]=length;
    }
}

void findk(int k,int pos){
    int x=sarray[k-1],y=k+3;
    if(pos<x){
        cout<<pos<<" "<<x<<" "<<y<<endl;
        findk(k-1,pos);
    }
    else if(pos==x)
        cout<<'m'<<endl;
    else if(pos<(x+y))
        cout<<'o'<<endl;
    else{
        cout<<pos<<" "<<x<<" "<<y<<endl;
        findk(k-1,pos-x-y);
    }
}

int main(){
    cin>>n;
    n--;
    maxk();
    findk(initk,n);
    cout<<endl;
    for(int i=0;i<initk;i++){
        cout<<sarray[i]<<endl;
    }
}
