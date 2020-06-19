#include <iostream>
#include <stdlib.h>
using namespace std;

int road[1005][2],dp[1005][1005];

bool friendly(int a,int b){
    if(abs(a-b)<=4)
        return true;
    else
        return false;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>road[i][0];
    for(int i=0;i<n;i++)
        cin>>road[i][1];
    for(int i=0;i<n;i++){
        dp[0][i]=friendly(road[0][0],road[i][1]);
        dp[i][0]=friendly(road[i][0],road[0][1]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+friendly(road[i][0],road[j][1]));
        }
    }
    cout<<dp[n-1][n-1]<<endl;
}
