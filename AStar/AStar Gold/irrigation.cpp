#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int,int> fields[2005];
priority_queue<pair<int,int> > pq;
bool visited[2005];

int cost(pair<int,int> coord1,pair<int,int> coord2){
    return (coord1.first-coord2.first)*(coord1.first-coord2.first) + (coord1.second-coord2.second)*(coord1.second-coord2.second);
}

int main(){
    int n,c,totalcost=0;
    pair<int,int> minim;
    cin>>n>>c;
    for(int i=0;i<n;i++)
        cin>>fields[i].first>>fields[i].second;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        minim=pq.top();
        pq.pop();
        minim.first*=-1;
        if(visited[minim.second])
            continue;
        visited[minim.second]=true;
        totalcost+=minim.first;
        for(int i=0;i<n;i++){
            if(!visited[i] && cost(fields[minim.second],fields[i])>=c)
                pq.push(make_pair(cost(fields[minim.second],fields[i])*-1,i));
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i])
            totalcost=-1;
    }
    cout<<totalcost<<endl;
}
