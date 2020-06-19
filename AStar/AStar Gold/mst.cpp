#include <iostream>
using namespace std;

int v,e,weights[2505],length;
short adj[2505][2505];
bool used[2505];

void findneighbor(int node){
    for(int i=1;i<=v;i++){
        if(adj[i][node]>0 && weights[i]>adj[i][node] && !used[i])
            weights[i]=adj[i][node];
    }
}

int main(){
    int inp1,inp2,inp3;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>inp1>>inp2>>inp3;
        adj[inp1][inp2]=inp3;
        adj[inp2][inp1]=inp3;
    }
    for(int i=2;i<=v;i++){
        weights[i]=1000000;
    }
    int minim=2000000,minindex;
    bool finished=false;
    while(1){
        finished=true;
        minim=2000000;
        for(int i=1;i<=v;i++){
            if(weights[i]<minim && !used[i]){
                minindex=i;
                minim=weights[i];
            }
            if(used[i]==false)
                finished=false;
        }
        if(finished)
            break;
        used[minindex]=true;
        length+=weights[minindex];
        findneighbor(minindex);
    }
    cout<<length<<endl;
}
