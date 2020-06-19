#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,pair<int,int> > > roads[10005];//first:new point,second.first:first gps,second.second:second gps
vector<pair<int,int> > complaints[10005];//first:complaints,second:index
priority_queue<pair<int,int> > pq; //first:dist,second:index
int dist1[10005],dist2[10005],dist3[10005];

int main(){
    int n,m,inputa,inputb,inputp,inputq,counter;
    pair<int,int> minim;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>inputa>>inputb>>inputp>>inputq;
        roads[inputb].push_back(make_pair(inputa,make_pair(inputp,inputq)));
    }
    fill(dist1+1,dist1+n+1,-1);
    fill(dist2+1,dist2+n+1,-1);
    fill(dist3+1,dist3+n+1,-1);
    pq.push(make_pair(0,n));
    while(!pq.empty()){
        minim=pq.top();
        minim.first*=-1;
        pq.pop();
        if(dist1[minim.second]>=0)
            continue;
        dist1[minim.second]=minim.first;
        for(int i=0;i<roads[minim.second].size();i++){
            if(dist1[roads[minim.second][i].first]==-1)
                pq.push(make_pair((minim.first+roads[minim.second][i].second.first)*-1,roads[minim.second][i].first));
        }
    }
    pq.push(make_pair(0,n));
    while(!pq.empty()){
        minim=pq.top();
        minim.first*=-1;
        pq.pop();
        if(dist2[minim.second]>=0)
            continue;
        dist2[minim.second]=minim.first;
        for(int i=0;i<roads[minim.second].size();i++){
            if(dist2[roads[minim.second][i].first]==-1)
                pq.push(make_pair((minim.first+roads[minim.second][i].second.second)*-1,roads[minim.second][i].first));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<roads[i].size();j++){
            counter=0;
            if(dist1[roads[i][j].first]!=(dist1[i]+roads[i][j].second.first))
                counter++;
            if(dist2[roads[i][j].first]!=(dist2[i]+roads[i][j].second.second))
                counter++;
            complaints[roads[i][j].first].push_back(make_pair(i,counter));
        }
    }
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        minim=pq.top();
        minim.first*=-1;
        pq.pop();
        if(dist3[minim.second]>=0)
            continue;
        dist3[minim.second]=minim.first;
        for(int i=0;i<complaints[minim.second].size();i++){
            if(dist3[complaints[minim.second][i].first]==-1)
                pq.push(make_pair((minim.first+complaints[minim.second][i].second)*-1,complaints[minim.second][i].first));
        }
    }
    cout<<dist3[n]<<endl;
}
