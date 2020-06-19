#include <iostream>
#include <algorithm>
using namespace std;

int n,l,clumps[1005],dp[1005][1005][2],minim=1000000000;

int recursedp(int l,int r,int s){
    int eaten=n-(r-l);
    if(l==1 && s==0){//s=0
        if(dp[l-1][r][1]==-1)
            dp[l-1][r][1]=recursedp(l-1,r,1);
        dp[l][r][s]=dp[l-1][r][1]+eaten*(clumps[r]-clumps[l]);
    }
    else if(l==0){//s=1
        if(dp[l][r+1][1]==-1)
            dp[l][r+1][1]=recursedp(l,r+1,1);
        dp[l][r][s]=dp[l][r+1][1]+eaten*(clumps[r+1]-clumps[r]);
    }
    else if(r==n && s==1){//s=1
        if(dp[l][r+1][0]==-1)
            dp[l][r+1][0]=recursedp(l,r+1,0);
        dp[l][r][s]=dp[l][r+1][0]+eaten*(clumps[r]-clumps[l]);
    }
    else if(r==n+1){//s=0
        if(dp[l-1][r][0]==-1)
            dp[l-1][r][0]=recursedp(l-1,r,0);
        dp[l][r][s]=dp[l-1][r][0]+eaten*(clumps[l]-clumps[l-1]);
    }
    else{
        if(s==0){
            if(dp[l-1][r][0]==-1)
                dp[l-1][r][0]=recursedp(l-1,r,0);
            if(dp[l-1][r][1]==-1)
                dp[l-1][r][1]=recursedp(l-1,r,1);
            dp[l][r][s]=min(dp[l-1][r][0]+eaten*(clumps[l]-clumps[l-1]),dp[l-1][r][1]+eaten*(clumps[r]-clumps[l]));
        }
        else{
            if(dp[l][r+1][0]==-1)
                dp[l][r+1][0]=recursedp(l,r+1,0);
            if(dp[l][r+1][1]==-1)
                dp[l][r+1][1]=recursedp(l,r+1,1);
            dp[l][r][s]=min(dp[l][r+1][0]+eaten*(clumps[r]-clumps[l]),dp[l][r+1][1]+eaten*(clumps[r+1]-clumps[r]));
        }
    }
    return dp[l][r][s];
}

int main(){
    cin>>n>>l;
    for(int i=1;i<=n;i++)
        cin>>clumps[i];
    sort(clumps+1,clumps+n+1);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    dp[0][n][1]=0;
    dp[1][n+1][0]=0;
    if(l<clumps[1])
        cout<<recursedp(0,1,1)+n*(clumps[1]-l)<<endl;
    else if(l>clumps[n])
        cout<<recursedp(n,n+1,0)+n*(l-clumps[n])<<endl;
    else{
        for(int i=1;i<=n;i++){
            if(l>clumps[i] && l<clumps[i+1]){
                recursedp(i,i+1,0);
                recursedp(i,i+1,1);
                cout<<min(dp[i][i+1][0]+n*(l-clumps[i]),dp[i][i+1][1]+n*(clumps[i+1]-l))<<endl;
                break;
            }
        }
    }
}
