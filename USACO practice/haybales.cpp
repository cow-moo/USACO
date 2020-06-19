#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int haybales[100005];

int n,q;

int binary(int num){
    int l=0,r=n-1,m;
    while(l<=r){
        m=(l+r)/2;
        if(num>haybales[(l+r)/2])
            l=m+1;
        else if(num<haybales[(l+r)/2])
            r=m-1;
        if(num>=haybales[m] && (num<haybales[m+1] || m+1==n))
            return m+1;
    }
}

int main(){
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int a,b,counter;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>haybales[i];
    }
    sort(haybales,haybales+n);
    for(int i=0;i<q;i++){
        cin>>a>>b;
        cout<<binary(b)-binary(a-1)<<endl;
    }
}
