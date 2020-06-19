#include <iostream>
using namespace std;

int fj[100005],dp[100005][21][3],wins[3]={2,0,1};//wins[i]==j, i beats j
//dp[i][j][k], the max wins in the first i games with j switches and currently using k

int main(){
    int n,k,maxim=0;
    char input;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>input;
        if(input=='H')
            fj[i]=0;
        else if(input=='P')
            fj[i]=1;
        else
            fj[i]=2;
    }
    for(int switches=0;switches<=k;switches++){
        for(int games=1;games<=n;games++){
            for(int cur=0;cur<3;cur++){
                dp[games][switches][cur]=max(dp[games][switches][cur],dp[games-1][switches][cur]+(wins[cur]==fj[games]));
                if(switches==k)
                    continue;
                for(int newc=0;newc<3;newc++){
                    if(newc!=cur)
                        dp[games][switches+1][newc]=max(dp[games][switches+1][newc],dp[games-1][switches][cur]+(wins[newc]==fj[games]));
                }
            }
        }
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<3;j++){
            if(dp[n][i][j]>maxim)
                maxim=dp[n][i][j];
        }
    }
    cout<<maxim<<endl;
}
