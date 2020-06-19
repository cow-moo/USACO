#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

bool visited[105][105];
bool edges[105][105][4];
bool cowspace[105][105];
int cowpos[105][2];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,k,r,counter=0;

queue<int> quer;
queue<int> quec;

void bfs(int cow){
    quer.push(cowpos[cow][0]);
    quec.push(cowpos[cow][1]);
    visited[quer.front()][quec.front()]=1;
    while(!quer.empty()){
        for(int i=0;i<4;i++){
            if(quer.front()+dir[i][0]<0 || quer.front()+dir[i][0]>=n || quec.front()+dir[i][1]<0 || quec.front()+dir[i][1]>=n)
                continue;
            if(!visited[quer.front()+dir[i][0]][quec.front()+dir[i][1]] && !edges[quer.front()][quec.front()][i]){
                quer.push(quer.front()+dir[i][0]);
                quec.push(quec.front()+dir[i][1]);
                visited[quer.back()][quec.back()]=1;
                if(cowspace[quer.back()][quec.back()]){
                    counter++;
                }
            }
        }
        quer.pop();
        quec.pop();
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            visited[i][j]=0;
        }
    }
}

int main(){
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);
    int tempr1,tempc1,tempr2,tempc2;
    cin>>n>>k>>r;
    for(int i=0;i<r;i++){
        cin>>tempr1>>tempc1>>tempr2>>tempc2;
        for(int j=0;j<4;j++){
            if((tempr1-tempr2)==dir[j][0] && (tempc1-tempc2)==dir[j][1])
                edges[tempr2-1][tempc2-1][j]=1;
            if((tempr2-tempr1)==dir[j][0] && (tempc2-tempc1)==dir[j][1])
                edges[tempr1-1][tempc1-1][j]=1;
        }
    }
    for(int i=0;i<k;i++){
        cin>>cowpos[i][0]>>cowpos[i][1];
        cowpos[i][0]--; cowpos[i][1]--;
        cowspace[cowpos[i][0]][cowpos[i][1]]=1;
    }
    for(int i=0;i<k;i++){
        bfs(i);
    }
    cout<<(k*(k-1)-counter)/2<<endl;
}
