#include <iostream>
using namespace std;

string dict[1005],pwd,dp[1005];

int l,dw;

bool fits(int wordindex,int pwdindex){
    for(int i=0;i<dict[wordindex].size();i++){
        if(i<l && dict[wordindex][i]!=pwd[pwdindex+i] && pwd[pwdindex+i]!='?')
            return 0;
    }
    return 1;
}

int main(){
    cin>>l>>dw;
    cin>>pwd;
    for(int i=0;i<dw;i++){
        cin>>dict[i];
    }
    for(int i=l-1;i>=0;i--){
        for(int j=0;j<dw;j++){
            if(fits(j,i) && i+dict[j].size()<=l && (i+dict[j].size()==l || dp[i+dict[j].size()]!="") && (dp[i]>dict[j]+dp[i+dict[j].size()] || dp[i]=="")){
                dp[i]=dict[j]+dp[i+dict[j].size()];
            }
        }
    }
    cout<<dp[0]<<endl;
}
