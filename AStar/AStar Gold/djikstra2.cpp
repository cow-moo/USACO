#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

priority_queue<pair<int,int> > dist;
int v,e,s;
vector<pair<int,int> > adj[50005];
int used[50005];

void findneighbor(int node){
    for(int i=0;i<adj[node].size();i++){
        if(!used[adj[node][i].first])
            dist.push(make_pair((adj[node][i].second+used[node])*-1,adj[node][i].first));
    }
}

int main(){
    int inp1,inp2,inp3;
    pair<int,int> minim;
    cin>>v>>e>>s;
    for(int i=0;i<e;i++){
        cin>>inp1>>inp2>>inp3;
        adj[inp1].push_back(make_pair(inp2,inp3));
        adj[inp2].push_back(make_pair(inp1,inp3));
    }
    dist.push(make_pair(0,s));
    while(!dist.empty()){
        minim=dist.top();
        dist.pop();
        minim.first=minim.first*-1;
        if(used[minim.second])
            continue;
        used[minim.second]=minim.first;
        findneighbor(minim.second);
    }
    for(int i=1;i<=v;i++){
        if(i==s)
            cout<<0<<endl;
        else if(used[i]>0)
            cout<<used[i]<<endl;
        else
            cout<<-1<<endl;
    }
}
