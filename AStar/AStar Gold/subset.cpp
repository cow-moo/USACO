#include <iostream>
using namespace std;

long long dp[1000];

int main(){
    int n,halfsum;
    cin>>n;
    if(n*(n+1)%4!=0)
        cout<<0<<endl;
    else{
        halfsum=n*(n+1)/4;
        dp[0]=1;
        for(int used=1;used<=n;used++){
            for(int i=halfsum-used;i>=0;i--){
                dp[i+used]+=dp[i];
            }
        }
        cout<<dp[halfsum]/2<<endl;
    }
}
