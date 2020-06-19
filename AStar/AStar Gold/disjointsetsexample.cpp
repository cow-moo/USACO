#include <iostream>
using namespace std;

int parent[1000000],n;//# of nodes
int treesize[1000000];//or treedepth

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
}

int main(){
    for(int i=1;i<=n;i++){
        treesize[i]=1;
        parent[i]=i;
    }
}
