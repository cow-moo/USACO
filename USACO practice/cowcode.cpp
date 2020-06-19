#include <iostream>
#include <stdio.h>
using namespace std;

long long n;

char recurse(string str,long long pos){
    if(pos<str.length()){
        return str[pos];
    }
    long long length = str.length();
    while((2*length)<=pos){
        length=length*2;
    }
    if(length==pos){
        return recurse(str,length-1);
    }
    return recurse(str,pos-length-1);
}

int main(){
    freopen("cowcode.in","r",stdin);
    freopen("cowcode.out","w",stdout);
    string str;
    cin>>str>>n;
    //long long temp=str.length();
    /*for(int i=0;;i++){
        if(temp>n)
            recurse(n,i);
    }*/
    cout<<recurse(str,n-1)<<endl;
}

