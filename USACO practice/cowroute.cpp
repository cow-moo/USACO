#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int adj[1050][1050];
int input[105];
int prev[1050];
int dist[1050];

int main(){
    //freopen("cowroute.in","r",stdin);
    //freopen("cowroute.out","w",stdout);
    int a,b,n,cost,routecount;
    cin>>a>>b>>n;
    for(int i=0;i<n;i++){
        cin>>cost>>routecount;
        for(int j=0;j<routecount;j++)
            cin>>input[j];
        for(int j=1;j<routecount;j++){
            for(int k=0;k<j;k++){
                if(adj[i][j]==0)
                    adj[k][j]=cost;
                else
                    adj[k][j]=min(cost,adj[k][j]);
            }
        }
    }
    for(int i=1;i<=1000;i++){
        dist[i]=2000000000;
    }
    dist[a]=0;
    bool finished;
    int minim;
    while(1){
        finished=true;
        minim=2000000000;
        for(int i=1;i<=1000;i++){
            if(dist[i]<minim)
        }
    }
}
