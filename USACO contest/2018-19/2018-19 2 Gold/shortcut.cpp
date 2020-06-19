#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

class Compare
{
public:
    bool operator() (pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
        if(a.first>b.first || (a.first==b.first && a.second.first>b.second.first))
            return true;
        else
            return false;
    }
};

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,Compare> next;//negative dist to 1,prev node,cur node
vector<pair<int,int> > adj[10005];//i is start,first is next,second is cost
long long dist[10005];//1 indexed
int prev[10005];
int visited[10005];
int cows[10005];//1 indexed

void findneighbor(int node){
    for(vector<pair<int,int> >::iterator it=adj[node].begin();it!=adj[node].end();++it){
        if(dist[(*it).first]==0)
            next.push(make_pair(((*it).second+dist[node]),make_pair(node,(*it).first)));
    }
}

int main(){
    freopen("shortcut.in","r",stdin);
    freopen("shortcut.out","w",stdout);
    int n,m,t;
    int inp1,inp2,inp3;
    pair<int,pair<int,int> > minim;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        cin>>cows[i];
    for(int i=0;i<m;i++){
        cin>>inp1>>inp2>>inp3;
        adj[inp1].push_back(make_pair(inp2,inp3));
        adj[inp2].push_back(make_pair(inp1,inp3));
    }
    next.push(make_pair(0,make_pair(0,1)));
    while(!next.empty()){
        minim=next.top();
        next.pop();
        //minim.first=minim.first*-1;
        //minim.second.first*=-1;
        //cout<<minim.first<<" "<<minim.second.first<<" "<<minim.second.second<<endl;
        if(dist[minim.second.second]>0)
            continue;
        //cout<<"used:"<<minim.second.first<<" "<<minim.second.second<<endl;
        dist[minim.second.second]=minim.first;
        prev[minim.second.second]=minim.second.first;
        findneighbor(minim.second.second);
    }
    dist[1]=0;
    prev[1]=0;
    /*cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<prev[i]<<endl;
    cout<<endl;*/
    int curi;
    for(int i=2;i<=n;i++){
        curi=i;
        while(curi!=1){
            visited[curi]+=cows[i];
            curi=prev[curi];
        }
    }
    long long maxsave=0;
    for(int i=2;i<=n;i++){
        if((dist[i]-t)*visited[i]>maxsave)
            maxsave=(dist[i]-t)*visited[i];
    }
    cout<<maxsave<<endl;
    //for(int i=1;i<=5;i++)
    //    cout<<i<<" "<<visited[i]<<endl;

}
