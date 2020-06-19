#include <iostream>
using namespace std;

int bales[25];
bool dp[2][800][800];

int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>bales[i];
        sum+=bales[i];
    }
    dp[1][0][0]=1;
    for(int cur=0;cur<n;cur++){
        for(int i=0;i<=700;i++){
            for(int j=0;j<=700;j++){
                if(dp[1-cur%2][i][j]){
                    dp[cur%2][i+bales[cur]][j]=1;
                    dp[cur%2][i][j+bales[cur]]=1;
                    dp[cur%2][i][j]=1;
                }
            }
        }
    }
    int minim=1000000;
    for(int i=0;i<=800;i++){
        for(int j=0;j<=800;j++){
            if(dp[1-n%2][i][j])
                minim=min(minim,max(max(i,j),sum-i-j));
        }
    }
    cout<<minim<<endl;
}
