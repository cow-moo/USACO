#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

priority_queue<pair<int,int> > weights;
int v,e,length;
vector<pair<int,int> > adj[50005];
bool used[50005];

void findneighbor(int node){
    for(int i=0;i<adj[node].size();i++){
        if(!used[adj[node][i].first])
            weights.push(make_pair((adj[node][i].second)*-1,adj[node][i].first));
    }
}

int main(){
    int inp1,inp2,inp3;
    pair<int,int> minim;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>inp1>>inp2>>inp3;
        adj[inp1].push_back(make_pair(inp2,inp3));
        adj[inp2].push_back(make_pair(inp1,inp3));
    }
    weights.push(make_pair(0,1));
    while(!weights.empty()){
        minim=weights.top();
        weights.pop();
        minim.first=minim.first*-1;
        if(used[minim.second])
            continue;
        used[minim.second]=true;
        length+=minim.first;
        findneighbor(minim.second);
    }
    cout<<length<<endl;
}
