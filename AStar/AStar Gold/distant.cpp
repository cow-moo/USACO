#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n,a,b,dist[35][35],maxim=0,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool pastures[35][35];
priority_queue<pair<int,pair<int,int> > > pq;

void djikstra(int startx,int starty){
    int newx,newy;
    pair<int,pair<int,int> > minim;
    pq.push(make_pair(0,make_pair(startx,starty)));
    while(!pq.empty()){
        minim=pq.top();
        minim.first*=-1;
        pq.pop();
        if(dist[minim.second.first][minim.second.second]>=0)
            continue;
        dist[minim.second.first][minim.second.second]=minim.first;
        for(int i=0;i<4;i++){
            newx=minim.second.first+dir[i][0];
            newy=minim.second.second+dir[i][1];
            if(dist[newx][newy]==-1 && newx>=0 && newx<n && newy>=0 && newy<n){
                if(pastures[minim.second.first][minim.second.second]==pastures[newx][newy])
                    pq.push(make_pair((minim.first+a)*-1,make_pair(newx,newy)));
                else
                    pq.push(make_pair((minim.first+b)*-1,make_pair(newx,newy)));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]>maxim)
                maxim=dist[i][j];
            dist[i][j]=-1;
        }
    }
}

int main(){
    string input;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>input;
        for(int j=0;j<n;j++){
            pastures[i][j]=(input[j]=='(');
            dist[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            djikstra(i,j);
    }
    cout<<maxim<<endl;
}
