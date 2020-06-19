#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int enjoyment[100050];//1-index
int parent[100050];
int level[100050];
vector<int> edges[100050];//1-index
queue<int> que;//node,level

int query(int node1,int node2){
    int enjoy1=enjoyment[node1],enjoy2=enjoyment[node2];
    while(node1!=node2){
        if(level[node1]>=level[node2]){
            node1=parent[node1];
            enjoy1=enjoy1^enjoyment[node1];
        }
        if(level[node2]>level[node1]){
            node2=parent[node2];
            enjoy2=enjoy2^enjoyment[node2];
        }
    }
    return enjoy1^enjoy2^enjoyment[node1];
}

int main(){
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);
    int n,q,inp1,inp2,inp3;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>enjoyment[i];
    for(int i=0;i<n-1;i++){
        cin>>inp1>>inp2;
        edges[inp1].push_back(inp2);
        edges[inp2].push_back(inp1);
    }
    level[1]=1;
    que.push(1);
    while(!que.empty()){
        for(vector<int>::iterator it=edges[que.front()].begin();it!=edges[que.front()].end();++it){
            if(level[*it]==0){
                parent[*it]=que.front();
                level[*it]=level[que.front()]+1;
                que.push(*it);
            }
        }
        que.pop();
    }
    for(int i=0;i<q;i++){
        cin>>inp1>>inp2>>inp3;
        if(inp1==1)
            enjoyment[inp2]=inp3;
        else
            cout<<query(inp2,inp3)<<endl;
    }
}
