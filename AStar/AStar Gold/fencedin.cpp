#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

short dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int fencea[2001],fenceb[2001];
priority_queue<pair<int,pair<short,short> > > pq;
bool visited[2001][2001];

int main(){
    int a,b,n,m,newx,newy;
    long long totalfence=0;
    pair<int,pair<short,short> > minim;
    cin>>a>>b>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>fencea[i];
    sort(fencea+1,fencea+n+1);
    fencea[n+1]=a;
    for(int i=1;i<=m;i++)
        cin>>fenceb[i];
    sort(fenceb+1,fenceb+m+1);
    fenceb[m+1]=b;
    pq.push(make_pair(0,make_pair(0,0)));
    while(!pq.empty()){
        minim=pq.top();
        pq.pop();
        minim.first=minim.first*-1;
        if(visited[minim.second.first][minim.second.second])
            continue;
        visited[minim.second.first][minim.second.second]=true;
        totalfence+=minim.first;
        for(int i=0;i<4;i++){
            newx=minim.second.first+dir[i][0];
            newy=minim.second.second+dir[i][1];
            if(newx==n+1 || newx<0 || newy==m+1 || newy<0)
                continue;
            else if(!visited[newx][newy]){
                if(dir[i][0]==0)
                    pq.push(make_pair((fencea[newx+1]-fencea[newx])*-1,make_pair(newx,newy)));
                else
                    pq.push(make_pair((fenceb[newy+1]-fenceb[newy])*-1,make_pair(newx,newy)));
            }
        }
    }
    cout<<totalfence<<endl;
}
