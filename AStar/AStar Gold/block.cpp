#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,r,min1,min2=1000000,parent[5005];
vector<pair<int,int> > edges[5005];
priority_queue<pair<int,pair<int,int> > > que;
int dist[5005],shortest=1000000;
//solution is either a backtrack from the main path or a separate path(dfs)
void dfs(int curnode,int curlength){
    if(curnode==n && curlength!=dist[n]){
        shortest=min(curlength,shortest);
        return;
    }
    for(int i=0;i<edges[curnode].size();i++){
        if(curlength+edges[curnode][i].second<shortest)
            dfs(edges[curnode][i].first,curlength+edges[curnode][i].second);
    }
}

int main(){
    int input1,input2,input3,backnode,minback=1000000;
    pair<int,pair<int,int> > minim;
    cin>>n>>r;
    fill(dist+1,dist+n+1,-1);
    for(int i=0;i<r;i++){
        cin>>input1>>input2>>input3;
        edges[input1].push_back(make_pair(input2,input3));
        edges[input2].push_back(make_pair(input1,input3));
    }
    que.push(make_pair(0,make_pair(1,1)));
    while(!que.empty()){
        minim=que.top();
        minim.first*=-1;
        que.pop();
        if(dist[minim.second.second]!=-1)
            continue;
        dist[minim.second.second]=minim.first;
        parent[minim.second.second]=minim.second.first;
        for(int i=0;i<edges[minim.second.second].size();i++){
            if(dist[edges[minim.second.second][i].first]==-1)
                que.push(make_pair((edges[minim.second.second][i].second+dist[minim.second.second])*-1,make_pair(minim.second.second,edges[minim.second.second][i].first)));
        }
    }
    backnode=n;
    while(backnode!=1){
        for(int i=0;i<edges[backnode].size();i++){
            if(edges[backnode][i].second<shortest)
                shortest=edges[backnode][i].second;
        }
        backnode=parent[backnode];
    }
    for(int i=0;i<edges[1].size();i++){
        if(edges[1][i].second<shortest)
            shortest=edges[1][i].second;
    }
    shortest=dist[n]+2*shortest;
    dfs(1,0);
    cout<<shortest<<endl;
}
