#include <iostream>
using namespace std;

bool dp[5000005];
int t,a,b;

void maxfull(){
    for(int i=0;i<t;i++){
        if(dp[i]){
            if(i+a<=t)
                dp[i+a]=1;
            if(i+b<=t)
                dp[i+b]=1;
        }
    }
}

int main(){
    cin>>t>>a>>b;
    dp[0]=1;
    maxfull();
    for(int i=0;i<t;i++){
        if(dp[i])
            dp[i/2]=1;
    }
    maxfull();
    for(int i=t;i>=0;i--){
        if(dp[i]){
            cout<<i<<endl;
            break;
        }
    }
}
