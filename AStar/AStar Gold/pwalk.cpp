#include <iostream>
#include <vector>
using namespace std;
//73570,51840
int n,q;
bool finished = false;
short adj[1005][1005];
vector<int> adj2[1005];
int dist[1005][1005];
int initial;

void dfs(int prev,int cur,int target,int length){
    dist[initial][cur]=length;
    if(finished)
        return;
    for(int i=0;i<adj2[cur].size();i++){
        if(adj[adj2[cur][i]][cur]>0 && adj2[cur][i]!=prev){
            if(adj2[cur][i]==target){
                length+=adj[adj2[cur][i]][cur];
                cout<<length<<endl;
                finished=true;
                return;
            }
            dfs(cur,adj2[cur][i],target,length+adj[adj2[cur][i]][cur]);
            if(finished)
                return;
        }
    }
}

int main(){
    int inp1,inp2,inp3;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        cin>>inp1>>inp2>>inp3;
        adj[inp1][inp2]=inp3;
        adj[inp2][inp1]=inp3;
        adj2[inp1].push_back(inp2);
        adj2[inp2].push_back(inp1);
    }
    for(int i=0;i<q;i++){
        cin>>inp1>>inp2;
        initial=inp1;
        if(dist[inp1][inp2]==0){
            dfs(-1,inp1,inp2,0);
        }
        else{
            cout<<dist[inp1][inp2]<<endl;
        }
        finished=false;
    }
}
