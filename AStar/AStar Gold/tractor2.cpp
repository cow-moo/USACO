#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int field[505][505],n,visitcount=0,treesize[505][505],maxim=0;
pair<int,int> parent[505][505];
vector<pair<pair<int,int>,pair<int,int> > > edges;

bool comparedifference(pair<pair<int,int>,pair<int,int> > edge1,pair<pair<int,int>,pair<int,int> > edge2){
    if(abs(field[edge1.first.first][edge1.first.second]-field[edge1.second.first][edge1.second.second]) == abs(field[edge2.first.first][edge2.first.second]-field[edge2.second.first][edge2.second.second]))
        return max(field[edge1.first.first][edge1.first.second],field[edge1.second.first][edge1.second.second]) < max(field[edge2.first.first][edge2.first.second],field[edge2.second.first][edge2.second.second]);
    return abs(field[edge1.first.first][edge1.first.second]-field[edge1.second.first][edge1.second.second]) < abs(field[edge2.first.first][edge2.first.second]-field[edge2.second.first][edge2.second.second]);
}

pair<int,int> root(pair<int,int> node){
    while(node!=parent[node.first][node.second]){
        parent[node.first][node.second]=parent[parent[node.first][node.second].first][parent[node.first][node.second].second];
        node=parent[node.first][node.second];
    }
    return node;
}

bool connected(pair<int,int> node1,pair<int,int> node2){
    return root(node1)==root(node2);
}

void join(pair<int,int> node1,pair<int,int> node2){
    pair<int,int> root1=root(node1);
    pair<int,int> root2=root(node2);
    if(treesize[root1.first][root1.second]>treesize[root2.first][root2.second]){
        parent[root2.first][root2.second]=root1;
        treesize[root1.first][root1.second]+=treesize[root2.first][root2.second];
    }
    else{
        parent[root1.first][root1.second]=root2;
        treesize[root2.first][root2.second]+=treesize[root1.first][root1.second];
    }
    visitcount++;
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>field[i][j];
            if(i+1<n)
                edges.push_back(make_pair(make_pair(i,j),make_pair(i+1,j)));
            if(j+1<n)
                edges.push_back(make_pair(make_pair(i,j),make_pair(i,j+1)));
            treesize[i][j]=1;
            parent[i][j].first=i;
            parent[i][j].second=j;
        }
    }
    sort(edges.begin(),edges.end(),comparedifference);
    for(int i=0;i<edges.size();i++){
        if(!connected(edges[i].first,edges[i].second)){
            join(edges[i].first,edges[i].second);
            maxim=max(maxim,abs(field[edges[i].first.first][edges[i].first.second]-field[edges[i].second.first][edges[i].second.second]));
        }
        if(treesize[root(edges[i].first).first][root(edges[i].second).second]>=(n*n+1)/2)
            break;
    }
    cout<<maxim<<endl;
}
