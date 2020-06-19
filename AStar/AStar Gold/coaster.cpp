#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<int,int,int,int> pieces[10005];
int dp[1005][1005];

int main(){
    int l,n,b,maxim=-1;
    cin>>l>>n>>b;
    for(int i=0;i<n;i++){
        cin>>get<0>(pieces[i])>>get<1>(pieces[i])>>get<2>(pieces[i])>>get<3>(pieces[i]);
    }
    sort(pieces,pieces+n);
    for(int i=0;i<=l;i++){
        for(int j=0;j<=b;j++)
            dp[i][j]=-1;
    }
    dp[0][0]=0;
    for(int cur=0;cur<n;cur++){
        for(int i=0;i<b-get<3>(pieces[cur]);i++){
            if(dp[get<0>(pieces[cur])][i]!=-1){
                dp[get<0>(pieces[cur])+get<1>(pieces[cur])][i+get<3>(pieces[cur])]=max(dp[get<0>(pieces[cur])][i]+get<2>(pieces[cur]),dp[get<0>(pieces[cur])+get<1>(pieces[cur])][i+get<3>(pieces[cur])]);
            }
        }
    }
    for(int i=0;i<=b;i++){
        if(dp[l][i]>maxim)
            maxim=dp[l][i];
    }
    cout<<maxim<<endl;
}
