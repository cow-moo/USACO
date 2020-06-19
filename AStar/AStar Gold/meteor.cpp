#include <iostream>
#include <queue>
#include <utility>
using namespace std;

//int meteors[50005][3];
int meteors[305][305],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}},m;
queue< pair<int,int> > que;
queue<int> quet;
bool visited[305][305];

bool canmove(int beginx,int beginy,int diri,int time){
    int newx = beginx+dir[diri][0];
    int newy = beginy+dir[diri][1];
    if(newx>=0 && newy>=0 && meteors[newx][newy]>time+1 && !visited[newx][newy])
        return true;
    else
        return false;
}

void bfs(){
    //int t=0;
    que.push(make_pair(0,0));
    quet.push(0);
    visited[0][0] = true;
    while(!que.empty()){
        for(int i=0;i<4;i++){
            if(canmove(que.front().first,que.front().second,i,quet.front())){
               que.push(make_pair(que.front().first+dir[i][0],que.front().second+dir[i][1]));
               quet.push(quet.front()+1);
               visited[que.back().first][que.back().second] = true;
            }
        }
        if(meteors[que.front().first][que.front().second]==1005){
            cout<<quet.front()<<endl;
            break;
        }
        //cout<<que.front().first<<" "<<que.front().second<<" "<<t<<endl;
        que.pop();
        quet.pop();
        //cout<<que.size()<<endl;
        //cout<<t<<endl;

    }
    if(que.empty())
        cout<<-1<<endl;
}

int main(){
    int mx,my,mt;
    cin>>m;
    for(int i=0;i<300;i++){
        for(int j=0;j<300;j++){
            meteors[i][j]=1005;
        }
    }
    for(int i=0;i<m;i++){
        cin>>mx>>my>>mt;
        if(mt<meteors[mx][my])
            meteors[mx][my]=mt;
        for(int i=0;i<4;i++){
            if(mx+dir[i][0]>=0 && my+dir[i][1]>=0 && mt<meteors[mx+dir[i][0]][my+dir[i][1]]){
                meteors[mx+dir[i][0]][my+dir[i][1]]=mt;
            }
        }
    }
    /*for(int i=0;i<=5;i++){
        for(int j=0;j<=5;j++){
            if(meteors[i][j]==1005)
                cout<<"* ";
            else
                cout<<meteors[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //cout<<canmove(0,0,0,1)<<endl;
    bfs();
}
