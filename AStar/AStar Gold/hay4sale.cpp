#include <iostream>
using namespace std;

bool dp[50005];
int bales[5005];

int main(){
    int c,h;
    cin>>c>>h;
    for(int i=0;i<h;i++){
        cin>>bales[i];
    }
    dp[0]=1;
    for(int cur=0;cur<h;cur++){
        for(int i=0;i<c-bales[cur];i++){
            if(dp[i])
                dp[i+bales[cur]]=1;
        }
    }
    for(int i=c-1;i>=0;i--){
        if(dp[i]){
            cout<<i+1<<endl;
            break;
        }
    }
}
