#include <iostream>
using namespace std;

int dp[2][10005];

int main(){
    int temp;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i%2][j]=dp[1-i%2][j-1]+1;
                continue;
            }
            if(dp[1-i%2][j]>dp[i%2][j])
                dp[i%2][j]=dp[1-i%2][j];
            if(dp[i%2][j-1]>dp[i%2][j])
                dp[i%2][j]=dp[i%2][j-1];
        }
    }
    cout<<dp[s1.size()%2][s2.size()]<<endl;
}
