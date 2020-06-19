#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int broken[100050];

int main(){
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    int n,k,b,temp,minimum=10000000;
    cin>>n>>k>>b;
    for(int i=0;i<b;i++){
        cin>>temp;
        for(int j=max(1,temp-k+1);j<=temp;j++)
            broken[j]++;
    }
    for(int i=1;i<=n-k+1;i++){
        if(broken[i]<minimum)
            minimum=broken[i];
    }
    cout<<minimum<<endl;
}
