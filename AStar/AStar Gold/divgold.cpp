#include <iostream>
using namespace std;

int dp[500005];
int coins[255];

int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>coins[i];
        sum+=coins[i];
    }
    fill(dp,dp+sum+1,-1);
    dp[0]=1;
    for(int used=0;used<n;used++){
        for(int i=sum-coins[used];i>=0;i--){
            if(dp[i]==-1)
                continue;
            if(dp[i+coins[used]]==-1)
                dp[i+coins[used]]=dp[i];
            else
                dp[i+coins[used]]=(dp[i+coins[used]]+dp[i])%1000000;
        }
    }
    for(int i=sum/2+(sum%2);i>=0;i--){
        if(dp[i]>-1){
            cout<<2*(sum/2-i)+3*(sum%2)<<endl;
            cout<<dp[i]<<endl;
            break;
        }
    }
}
