#include <iostream>
#include <deque>
#include <utility>
using namespace std;

deque<pair<int,int> > que;
deque<int> extrapad;
deque<long long> jumpc;
bool visited[35][35];
int m,n,dir[8][2]={{2,1},{1,2},{-2,1},{1,-2},{2,-1},{-1,2},{-2,-1},{-1,-2}};
int pond[35][35],minextra=1000000000,minjump=1000000000,paths=0;
/*
0: empty water
1: lilypad
2: rock
3: start
4: end
*/

void printvisited(){
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==que.front().first && j==que.front().second)
                cout<<2<<" ";
            else
                cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printque(){
    for(deque<pair<int,int> >::iterator i=que.begin();i!=que.end();i++){
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }
    cout<<endl;
}

bool canmove(int beginy,int beginx,int diri){
    int newy = beginy+dir[diri][0];
    int newx = beginx+dir[diri][1];
    if(newy>=0 && newy<m && newx>=0 && newx<n && pond[newy][newx]!=2 && visited[newy][newx]==0){
        return true;
    }
    else{
        return false;
    }
}

void bfs(int inity,int initx){
    que.push_back(make_pair(inity,initx));
    visited[inity][initx]=1;
    extrapad.push_back(0);
    jumpc.push_back(0);
    while(!que.empty()){
        //printque();
        //visited[que.front().first][que.back().second]=1;

        bool moved = false;
        int temp1 = que.front().first;
        int temp2 = que.front().second;
        int tempe = extrapad.front();
        int tempj = jumpc.front();
        que.pop_front();
        extrapad.po

        p_front();
        jumpc.pop_front();
        for(int i=0;i<8;i++){
            if(canmove(temp1,temp2,i)){
                moved = true;
                if(pond[temp1+dir[i][0]][temp2+dir[i][1]]==0){
                    que.push_back(make_pair(temp1+dir[i][0],temp2+dir[i][1]));
                    extrapad.push_back(tempe+1);
                    jumpc.push_back(tempj+1);
                    visited[que.back().first][que.back().second]=1;
                    //que.pop_front();
                    //extrapad.pop_front();
                    //jumpc.pop_front();
                }
                else if(pond[temp1+dir[i][0]][temp2+dir[i][1]]==1){
                    que.push_front(make_pair(temp1+dir[i][0],temp2+dir[i][1]));
                    extrapad.push_front(tempe);
                    jumpc.push_front(tempj+1);
                    visited[que.front().first][que.front().second]=1;
                    //que.erase(que.begin()+1);
                    //extrapad.erase(extrapad.begin()+1);
                    //jumpc.erase(jumpc.begin()+1);
                }
                else if(pond[temp1+dir[i][0]][temp2+dir[i][1]]==4){
                    if(tempe<=minextra){
                        minextra=tempe;
                        if(tempj<minjump){
                            minjump=tempj;
                            paths=1;
                        }
                        else if(tempj==minjump)
                            paths++;
                    }
                }
                //jumpc.push_back(jumpc.front()+1);
                //visited[que.back().first][que.back().second]=1;
                printvisited();
            }
        }
        /*if(pond[que.front().first][que.front().second]==4){
            moved=true;
            cout<<"big homo"<<endl;
            if(extrapad.front()<=minextra){
                minextra=extrapad.front();
                if(jumpc.front()<minjump){
                    minjump=jumpc.front();
                    paths=1;
                }
                else if(jumpc.front()==minjump)
                    paths++;
            }
            que.pop_front();
            extrapad.pop_front();
            jumpc.pop_front();
        }*/
        /*if(!moved){
            que.pop_front();
            extrapad.pop_front();
            jumpc.pop_front();
        }*/
    }
}

int main(){
    int starty,startx;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>pond[i][j];
            if(pond[i][j]==3){
                starty=i;
                startx=j;
            }
            /*else if(pond[i][j]==4){
                int endx=j;
                int endy=i;
            }*/
        }
    }
    //cout<<starty<<" "<<startx<<endl;
    //cout<<canmove(2,3,5)<<endl;
    //cout<<visited[2+dir[0][0]][3+dir[0][1]]<<endl;
    bfs(starty,startx);
    cout<<minextra<<endl;
    cout<<minjump+1<<endl;
    cout<<paths+1<<endl;
}
