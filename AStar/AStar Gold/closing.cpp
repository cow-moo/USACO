#include <iostream>
#include <vector>
using namespace std;

int n,m,parent[200005],treesize[200005],closeorder[200005];
bool open[200005],connect[200005];
vector<int> paths[200005];

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
    int input1,input2,curopen;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>input1>>input2;
        paths[input1].push_back(input2);
        paths[input2].push_back(input1);
    }
    for(int i=1;i<=n;i++){
        cin>>closeorder[i];
        parent[i]=i;
        treesize[i]=1;
    }
    for(int i=n;i>0;i--){
        curopen=closeorder[i];
        open[curopen]=true;
        for(int j=0;j<paths[curopen].size();j++){
            if(open[paths[curopen][j]])
                join(paths[curopen][j],curopen);
        }
        if(treesize[root(curopen)]==n-i+1)
            connect[i]=true;
    }
    for(int i=1;i<=n;i++){
        if(connect[i])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
