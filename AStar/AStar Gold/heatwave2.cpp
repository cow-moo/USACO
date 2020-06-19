#include <iostream>
using namespace std;

int v,e,s,dist[2505];
short adj[2505][2505];
bool used[2505];

void findneighbor(int node){
    for(int i=1;i<=v;i++){
        if(adj[i][node]>0 && dist[i]>adj[i][node]+dist[node] && !used[i])
            dist[i]=adj[i][node]+dist[node];
    }
}

int main(){
    int inp1,inp2,inp3,te;
    cin>>v>>e>>s>>te;
    for(int i=0;i<e;i++){
        cin>>inp1>>inp2>>inp3;
        adj[inp1][inp2]=inp3;
        adj[inp2][inp1]=inp3;
    }
    for(int i=1;i<=v;i++){
        dist[i]=1000000;
    }
    dist[s]=0;
    int minim=2000000,minindex;
    while(1){
        minim=2000000;
        for(int i=1;i<=v;i++){
            if(dist[i]<minim && !used[i]){
                minindex=i;
                minim=dist[i];
            }
        }
        used[minindex]=true;
        findneighbor(minindex);
        if(minindex==te)
            break;
    }
    cout<<dist[te]<<endl;
}
