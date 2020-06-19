#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> cows[1005];//x,y
vector<pair<int,int> > edges;//index 1,index 2
int parent[1005],treesize[1005],ans=0;

int dist(pair<int,int> pt1,pair<int,int> pt2){
    return (pt2.first-pt1.first)*(pt2.first-pt1.first) + (pt2.second-pt1.second)*(pt2.second-pt1.second);
}

bool comparedist(pair<int,int> edge1,pair<int,int> edge2){
    return dist(cows[edge1.first],cows[edge1.second]) < dist(cows[edge2.first],cows[edge2.second]);
}

int root(int node){
    while(node!=parent[node]){
        parent[node]=parent[parent[node]];
        node=parent[node];
    }
    return node;
}

bool connected(int node1,int node2){
    return root(node1)==root(node2);
}

void join(int node1,int node2){
    if(connected(node1,node2))
        return;
    int root1=root(node1);
    int root2=root(node2);
    if(treesize[root1]>treesize[root2]){
        parent[root2]=root1;
        treesize[root1]+=treesize[root2];
    }
    else{
        parent[root1]=root2;
        treesize[root2]+=treesize[root1];
    }
    ans=max(ans,dist(cows[node1],cows[node2]));
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        parent[i]=i;
        treesize[i]=1;
    }
    for(int i=0;i<n;i++)
        cin>>cows[i].first>>cows[i].second;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
            edges.push_back(make_pair(i,j));
    }
    sort(edges.begin(),edges.end(),comparedist);
    for(int i=0;i<edges.size();i++)
        join(edges[i].first,edges[i].second);
    cout<<ans<<endl;
}
