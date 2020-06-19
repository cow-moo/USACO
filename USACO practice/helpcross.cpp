#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

pair <int,int> ab[20005];

int t[20005];
bool cowused[20005];

int main(){
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int c,n,counter=0;
    cin>>c>>n;
    for(int i=0;i<c;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        cin>>ab[i].second>>ab[i].first;
    }
    sort(t,t+c);
    sort(ab,ab+n);
    for(int i=0;i<c;i++){
        for(int j=0;j<n;j++){
            if(ab[j].second<=t[i] && t[i]<=ab[j].first && !cowused[j]){
                counter++;
                cowused[j]=1;
                //cout<<ab[j].second<<" "<<t[i]<<" "<<ab[j].first<<endl;
                break;
            }
        }
    }
    cout<<counter<<endl;
}
