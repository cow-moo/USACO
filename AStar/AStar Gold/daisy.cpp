#include <iostream>
using namespace std;

bool adj[255][255],visited[255];
int n;

void dfs(int cnum){
    for(int i=1;i<=n;i++){
        if(adj[i][cnum] && !visited[i]){
            visited[i]=1;
            dfs(i);
        }
    }
}

int main(){
    int m,inp1,inp2;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>inp1>>inp2;
        adj[inp1][inp2]=1;
        adj[inp2][inp1]=1;
    }
    visited[1]=1;
    dfs(1);
    bool misbehave=false;
    for(int i=2;i<=n;i++){
        if(visited[i]==false){
            cout<<i<<endl;
            misbehave=true;
        }
    }
    if(!misbehave)
        cout<<0<<endl;
}
