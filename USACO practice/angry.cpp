#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int bales[50050];

int main(){
    //freopen("angry.in","r",stdin);
    //freopen("angry.out","w",stdout);
    int n,k,curbale,balecount;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>bales[i];
    sort(bales,bales+n);
    bales[n]=2000000000;
    for(int r=0;;r++){
        balecount=0;
        curbale=0;
        for(int i=1;i<=n;i++){
            if(bales[i]-bales[curbale]>2*r){
                curbale=i;
                balecount++;
            }
            if(balecount>k)
                break;
        }
        if(curbale==n && balecount<=k){
            cout<<r<<endl;
            break;
        }
    }
}
