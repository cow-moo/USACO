#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int t,c,ts,te,minim=10000000;
short adj[2500][2500];
deque<pair<int,int> > que;
bool visited[2500];

int bfs(){
    pair<int,int> temp;
    temp.first=ts;
    temp.second=0;
    que.push_front(temp);
    while(!que.empty()){
        if(que.front().first==te){
            //cout<<que.front().second<<" "<<endl;
            if(que.front().second<minim)
                minim = que.front().second;
            que.pop_front();
            continue;
        }
        for(int i=0;i<t;i++){
            if(!visited[i] && adj[que.front().first][i]){
                temp.first=i;
                temp.second=que.front().second+adj[que.front().first][i];
                if(temp.second>que.front().second)
                    que.push_back(temp);
                else
                    que.push_front(temp);
                //cout<<temp.first<<" "<<temp.second<<endl;
            }
        }
        visited[que.front().first]=1;
        que.pop_front();
        //cout<<que.size()<<endl;
    }
}

int main(){
    int temp1,temp2;
    cin>>t>>c>>ts>>te;
    ts--; te--;
    for(int i=0;i<c;i++){
        cin>>temp1>>temp2;
        cin>>adj[temp1-1][temp2-1];
        adj[temp2-1][temp1-1] = adj[temp1-1][temp2-1];
    }
    /*for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }*/
    bfs();
    cout<<minim<<endl;
}
