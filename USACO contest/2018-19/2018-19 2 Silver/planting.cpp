#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> adj[100005];
int grass[100005];
bool used[100005];

int main(){
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    int n,inp1,inp2,maxgrass=0,start;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>inp1>>inp2;
        adj[inp1-1].push_back(inp2-1);
        adj[inp2-1].push_back(inp1-1);
    }
    for(int i=0;i<n;i++){
        start=0;
        used[grass[i]]=true;
        for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();++it){
            //*it is adj index
            if(used[grass[*it]]){
                for(int j=start;j<n;j++){
                    if(!used[j]){
                        grass[*it]=j;
                        start=j+1;
                        break;
                    }
                }
            }
            used[grass[*it]]=true;
            if(grass[*it]>maxgrass)
                maxgrass=grass[*it];
        }
        for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();++it)
            used[grass[*it]]=false;
        used[grass[i]]=false;
    }
    cout<<maxgrass+1<<endl;
}
