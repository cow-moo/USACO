#include <iostream>
#include <algorithm>
using namespace std;

int ants[100000];
int dp[2][100000];

int main(){
    int t,a,s,b,counter=0,cur=1,rsum,ans=0;
    cin>>t>>a>>s>>b;
    for(int i=0;i<a;i++)
        cin>>ants[i];
    sort(ants,ants+a);
    dp[0][0]=1;
    for(int i=0;i<=a;i++){
        if(ants[i]==cur)
            counter++;
        else{
            rsum=0;
            for(int i=0;i<=b;i++){
                if(i-counter-1>=0)
                    rsum=(rsum-dp[1-cur%2][i-counter-1])%1000000;
                if(rsum<0)
                    rsum+=1000000;
                rsum+=(dp[1-cur%2][i])%1000000;
                dp[cur%2][i]=rsum;
            }
            counter=1;
            cur++;
        }
    }
    for(int i=s;i<=b;i++)
        ans=(ans+dp[1-cur%2][i])%1000000;
    if(ans<0)
        ans+=1000000;
    cout<<ans<<endl;
}
