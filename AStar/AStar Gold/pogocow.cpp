#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> targets[1005]; //.first:x .second:p
int dp[1005][1005];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>targets[i].first>>targets[i].second;//1-N
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;
    }
    sort(targets,targets+n);
    //dp[1][0]=
    for(int i=1;i<=n;i++){
        dp[i][0]=targets[i].second;
        for(int j=1;j<i;j++){
            if(targets[i].first)
            if(dp[i][j]!=-1){

            }
        }
    }
}
