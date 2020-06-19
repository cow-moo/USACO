#include <iostream>
using namespace std;

void solve(){
    int n,b,heights[25],sum,ans=1000000;
    cin>>n>>b;
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    for(int i=0;i<(1<<n);i++){
        sum=0;
        for(int j=0;j<n;j++){
            sum+=heights[j]*((i>>j)%2);
        }
        if(sum>=b && sum<ans)
            ans=sum;
    }
    cout<<ans-b<<endl;
}

int main(){
    solve();
}
