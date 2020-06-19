#include <iostream>
using namespace std;

int dp[2][5005],coins[5005];

int main(){
    int n,maxim=0,rsum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>coins[i];
    for(int length=1;length<=n;length++){
        rsum=0;
        for(int i=0;i<length;i++)
            rsum+=coins[i];
        for(int i=0;i<=n-length;i++){
            dp[length%2][i]=rsum-min(dp[1-length%2][i+1],dp[1-length%2][i]);
            rsum-=coins[i];
            rsum+=coins[i+length];
        }
    }
    cout<<dp[n%2][0]<<endl;
}
