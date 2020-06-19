#include <iostream>
using namespace std;

int dp[1005][1005][2],coordh[1005][2],coordg[1005][2];

int dist(int first[2],int second[2]){
    return (second[0]-first[0])*(second[0]-first[0]) + (second[1]-first[1])*(second[1]-first[1]);
}

int main(){
    int maxh,maxg;
    cin>>maxh>>maxg;
    for(int i=1;i<=maxh;i++)
        cin>>coordh[i][0]>>coordh[i][1];
    for(int i=1;i<=maxg;i++)
        cin>>coordg[i][0]>>coordg[i][1];
    for(int i=0;i<=maxh;i++){
        for(int j=0;j<=maxg;j++){
            dp[i][j][0]=2000000000;
            dp[i][j][1]=2000000000;
        }
    }
    dp[1][0][0]=0;
    dp[0][1][1]=0;
    for(int firsth=1;firsth<=maxh;firsth++){
        for(int firstg=0;firstg<=maxg;firstg++){
            if(firsth+1<=maxh){
                dp[firsth+1][firstg][0]=min(dp[firsth+1][firstg][0],dp[firsth][firstg][0]+dist(coordh[firsth],coordh[firsth+1]));
                dp[firsth+1][firstg][0]=min(dp[firsth+1][firstg][0],dp[firsth][firstg][1]+dist(coordg[firstg],coordh[firsth+1]));
            }
            if(firstg+1<=maxg){
                dp[firsth][firstg+1][1]=min(dp[firsth][firstg+1][1],dp[firsth][firstg][0]+dist(coordh[firsth],coordg[firstg+1]));
                dp[firsth][firstg+1][1]=min(dp[firsth][firstg+1][1],dp[firsth][firstg][1]+dist(coordg[firstg],coordg[firstg+1]));
            }
        }
    }
    cout<<dp[maxh][maxg][0]<<endl;
}
