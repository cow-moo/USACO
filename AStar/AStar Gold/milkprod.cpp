#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<pair<int,int>,int> intervals[1005];
int dp[1005];

int main(){
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0;i<m;i++){
        cin>>intervals[i].first.first>>intervals[i].first.second>>intervals[i].second;
    }
    sort(intervals,intervals+m);
    for(int i=0;i<m;i++){
        dp[i]=0;
        for(int j=i-1;j>=0;j--){
            if(intervals[j].first.second+r<=intervals[i].first.first){
                dp[i]=max(dp[j],dp[i]);
            }
        }
        dp[i]+=intervals[i].second;
    }
    cout<<*max_element(dp,dp+m)<<endl;
}
