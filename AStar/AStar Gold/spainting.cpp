#include <iostream>
using namespace std;

long long dp[1000005];

long long exponent(int base,int power){
    long long output=1;
    for(int i=0;i<power;i++)
        output=(output*base)%1000000007;
    if(output<0)
        output+=1000000007;
    return output;
}

int main(){
    int n,m,k;
    long long rsum;
    cin>>n>>m>>k;
    dp[0]=m;
    rsum=m;
    for(int i=1;i<k-1;i++){
        dp[i]=(dp[i-1]*m)%1000000007;
        rsum=(rsum+dp[i])%1000000007;
    }
    for(int i=k-1;i<n;i++){
        dp[i]=(rsum*(m-1))%1000000007;
        rsum-=dp[i-k+1];
        rsum=(rsum+dp[i])%1000000007;
    }
    if(exponent(m,n)-dp[n-1]<0)
        cout<<(exponent(m,n)-dp[n-1]+1000000007)%1000000007;
    else
        cout<<(exponent(m,n)-dp[n-1])%1000000007<<endl;
}
