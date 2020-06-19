#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> extrainp,extraout;
int platforms[10005];
vector<int> adj[10005];
int inptimes[10005],outtimes[10005];

int main(){
    int n,m,inp1,inp2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>platforms[i];
    }
    for(int i=0;i<m;i++){
        cin>>inp1>>inp2;
        inptimes[inp2]++;
        inptimes[inp1]--;
    }
    for(int i=1;i<=n;i++){
        if(inptimes[i]>0){
            for(int j=0;j<inptimes[i];j++)
                extrainp.push_back(platforms[i]);
        }
        else if(inptimes[i]<0){
            inptimes[i]*=-1;
            for(int j=0;j<inptimes[i];j++)
                extraout.push_back(platforms[i]);
        }
    }
    sort(extrainp.begin(),extrainp.end());
    sort(extraout.begin(),extraout.end());
    int sum=0;
    for(int i=0;i<extrainp.size();i++){
        sum+=abs(extrainp[i]-extraout[i]);
    }
    cout<<sum<<endl;
}
