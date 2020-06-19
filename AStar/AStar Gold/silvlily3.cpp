#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

queue<tuple<int,int,int,int> > que;
tuple<int,int,long long> lilypadvalues[35][35];
int m,n,dir[8][2]={{2,1},{1,2},{-2,1},{1,-2},{2,-1},{-1,2},{-2,-1},{-1,-2}},pond[35][35];

void printlily(){
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<< get<0>(lilypadvalues[i][j]) <<" ";
        }
        cout<<endl;
    }
}

bool canmove(int beginy,int beginx,int diri){
    int newy = beginy+dir[diri][0];
    int newx = beginx+dir[diri][1];
    if(newy>=0 && newy<m && newx>=0 && newx<n && pond[newy][newx]!=2){
        return true;
    }
    else{
        return false;
    }
}

void bfs(int inity,int initx){
    que.push(make_tuple(0,0,inity,initx));
    get<2>(lilypadvalues[inity][initx]) = 1;
    while(!que.empty()){
        int curpad = get<0>(que.front());
        int curjump = get<1>(que.front());
        int cury = get<2>(que.front());
        int curx = get<3>(que.front());
        que.pop();
        for(int i=0;i<8;i++){
            int newy = cury+dir[i][0];
            int newx = curx+dir[i][1];
            if(canmove(cury,curx,i)){
                if(get<2>(lilypadvalues[newy][newx])==0){
                    get<0>(lilypadvalues[newy][newx])=curpad+1-pond[newy][newx];
                    get<1>(lilypadvalues[newy][newx])=curjump+1;
                    get<2>(lilypadvalues[newy][newx])=get<2>(lilypadvalues[cury][curx]);
                    que.push(make_tuple(get<0>(lilypadvalues[newy][newx]),get<1>(lilypadvalues[newy][newx]),newy,newx));
                }
                else if(get<0>(lilypadvalues[newy][newx]) > curpad+1-pond[newy][newx]){
                    get<0>(lilypadvalues[newy][newx])=curpad+1-pond[newy][newx];
                    get<1>(lilypadvalues[newy][newx])=curjump+1;
                    get<2>(lilypadvalues[newy][newx])=get<2>(lilypadvalues[cury][curx]);
                    que.push(make_tuple(get<0>(lilypadvalues[newy][newx]),get<1>(lilypadvalues[newy][newx]),newy,newx));
                }
                else if(get<0>(lilypadvalues[newy][newx]) == curpad+1-pond[newy][newx] && get<1>(lilypadvalues[newy][newx]) == curjump+1){
                    get<0>(lilypadvalues[newy][newx])=curpad+1-pond[newy][newx];
                    get<2>(lilypadvalues[newy][newx])+=get<2>(lilypadvalues[cury][curx]);
                }
            }
        }
    }
}

int main(){
    int starty,startx,endy,endx;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>pond[i][j];
            if(pond[i][j]==3){
                starty=i;
                startx=j;
                pond[i][j]=0;
            }
            else if(pond[i][j]==4){
                endy=i;
                endx=j;
                pond[i][j]=1;
            }
        }
    }
    bfs(starty,startx);
    if(get<2>(lilypadvalues[endy][endx])==0){
        cout<<-1<<endl;
    }
    else{
        cout<<get<0>(lilypadvalues[endy][endx])<<endl;
        cout<<get<1>(lilypadvalues[endy][endx])<<endl;
        cout<<get<2>(lilypadvalues[endy][endx])<<endl;
    }
}
