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
    int inp1,inp2,inp3;
    cin>>v>>e>>s;
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
    bool finished=false;
    while(1){
        finished=true;
        minim=2000000;
        for(int i=1;i<=v;i++){
            if(dist[i]<minim && !used[i]){
                minindex=i;
                minim=dist[i];
            }
            if(used[i]==false)
                finished=false;
        }
        if(finished)
            break;
        used[minindex]=true;
        findneighbor(minindex);
    }
    for(int i=1;i<=v;i++){
        if(dist[i]<1000000)
            cout<<dist[i]<<endl;
        else
            cout<<-1<<endl;
    }
}
