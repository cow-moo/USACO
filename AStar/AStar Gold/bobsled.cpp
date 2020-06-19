#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> turns[100005];//1:distance,2:speedlimit

int main(){
    int l,n,maxim=0;
    cin>>l>>n;
    for(int i=1;i<=n;i++)
        cin>>turns[i].first>>turns[i].second;
    sort(turns+1,turns+n+1);
    turns[0].first=0;
    turns[0].second=1;
    turns[n+1].first=l;
    turns[n+1].second=1000000000;
    for(int i=0;i<=n;i++)
        turns[i+1].second=min(turns[i].second+turns[i+1].first-turns[i].first,turns[i+1].second);
    for(int i=n+1;i>0;i--)
        turns[i-1].second=min(turns[i].second+turns[i].first-turns[i-1].first,turns[i-1].second);
    for(int i=0;i<=n;i++){
        if((turns[i+1].first-(turns[i+1].second-turns[i].second+turns[i].first))/2+turns[i+1].second>maxim)
            maxim=(turns[i+1].first-(turns[i+1].second-turns[i].second+turns[i].first))/2+turns[i+1].second;
    }
    cout<<maxim<<endl;
}
