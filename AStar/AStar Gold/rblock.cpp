#include <iostream>
#include <vector>
using namespace std;

int n,m,maxim;
int adj[105][105];
bool used[105];
pair<int,vector<int> > dist[105];
int dist1[105],used1[105];

void findneighbororiginal(int node){
    for(int i=1;i<=n;i++){
        if(adj[i][node]>0 && dist[i].first>adj[i][node]+dist[node].first && !used[i]){
            dist[i].first=adj[i][node]+dist[node].first;
            dist[i].second = dist[node].second;
            dist[i].second.push_back(i);
        }
    }
}

void findneighbor(int node){
    for(int i=1;i<=n;i++){
        if(adj[i][node]>0 && dist1[i]>adj[i][node]+dist1[node] && !used1[i]){
            dist1[i]=adj[i][node]+dist1[node];
        }
    }
}
void dijkstra(){
    for(int i=1;i<=n;i++){
        dist1[i]=1000000000;
    }
    for(int i=1;i<=n;i++)
        used1[i]=0;
    dist1[1]=0;
    int minim=2000000,minindex;
    while(1){
        minim=2000000;
        for(int i=1;i<=n;i++){
            if(dist1[i]<minim && !used1[i]){
                minindex=i;
                minim=dist1[i];
            }
        }
        if(minindex==n)
            break;
        used1[minindex]=true;
        findneighbor(minindex);
    }
    if(dist1[n]>maxim)
        maxim=dist1[n];
}

int main(){
    int inp1,inp2,inp3;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>inp1>>inp2>>inp3;
        adj[inp1][inp2]=inp3;
        adj[inp2][inp1]=inp3;
    }
    for(int i=1;i<=n;i++){
        dist[i].first=1000000000;
        dist[i].second.push_back(1);
    }
    dist[1].first=0;
    int minim=2000000,minindex;
    bool finished=false;
    while(1){
        finished=true;
        minim=2000000;
        for(int i=1;i<=n;i++){
            if(dist[i].first<minim && !used[i]){
                minindex=i;
                minim=dist[i].first;
            }
        }
        if(minindex==n)
            break;
        used[minindex]=true;
        findneighbororiginal(minindex);
    }
    for(int i=0;i<dist[n].second.size()-1;i++){
        adj[dist[n].second[i]][dist[n].second[i+1]]*=2;
        adj[dist[n].second[i+1]][dist[n].second[i]]*=2;
        dijkstra();
        adj[dist[n].second[i]][dist[n].second[i+1]]/=2;
        adj[dist[n].second[i+1]][dist[n].second[i]]/=2;
    }
    cout<<maxim-dist[n].first<<endl;
}
