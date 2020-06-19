#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> objects[1005];
int dp[5005];

int main(){
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>objects[i].first>>objects[i].second;
    }
    fill(dp,dp+c+1,-1);
    dp[0]=0;
    for(int cur=0;cur<n;cur++){
        for(int i=c-objects[cur].first;i>=0;i--){
            if(dp[i]!=-1){
                dp[i+objects[cur].first]=max(dp[i+objects[cur].first],dp[i]+objects[cur].second);
            }
        }
    }
    cout<<*max_element(dp,dp+c+1)<<endl;
}
