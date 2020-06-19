#include <iostream>
#include <stdio.h>
using namespace std;

int cowid[50005];

int main(){
    //freopen("div7.in","r",stdin);
    //freopen("div7.out","w",stdout);
    int n,maxcows=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>cowid[i];
    for(int i=1;i<n;i++){
        cowid[i]+=cowid[i-1];
        cowid[i]=cowid[i]%7;
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i+maxcows;j--){
            if(cowid[i]==cowid[j]){
                maxcows=j-i;
                break;
            }
        }
    }
    cout<<maxcows<<endl;
}
