#include <iostream>
using namespace std;

int n,k,dp[100005];

int main(){
    int sum=1;
    cin>>n>>k;
    for(int i=0;i<=k;i++)
        dp[i]=1;
    for(int i=k+1;i<n;i++){
        dp[i]=(dp[i-1]+dp[i-k-1])%5000011;
        sum=(sum+dp[i])%5000011;
    }
    cout<<sum+k+1<<endl;
}
