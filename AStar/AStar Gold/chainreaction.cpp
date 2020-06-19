#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> beacons[100005];
int destroynum[100005];
int dp[100005];

int main(){
    int n,destroyed,mind=1000000000,cur;
    cin>>n;
    fill(dp,dp+n,-1);
    for(int i=0;i<n;i++)
        cin>>beacons[i].first>>beacons[i].second;
    sort(beacons,beacons+n);
    for(int i=n-1;i>=0;i--){
        for(int j=1;i-j>=0;j++){
            if(beacons[i].first-beacons[i-j].first<=beacons[i].second)
                destroynum[i]++;
            else
                break;
        }
    }
    for(int rdestroy=0;rdestroy<mind;rdestroy++){
        destroyed=rdestroy;
        cur=n-1-rdestroy;
        while(cur>0){
            destroyed+=destroynum[cur];
            cur-=destroynum[cur]+1;
            if(dp[cur]!=-1){
                destroyed+=dp[cur];
                break;
            }
            else{
                dp[cur]=destroyed;
            }
        }
        dp[rdestroy]=destroyed;
        if(destroyed<mind)
            mind=destroyed;
    }
    cout<<mind<<endl;
}
