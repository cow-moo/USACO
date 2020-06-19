#include <iostream>
#include <utility>
using namespace std;

bool visitoriginal[35][35];
int m,n,dir[8][2]={{2,1},{1,2},{-2,1},{1,-2},{2,-1},{-1,2},{-2,-1},{-1,-2}};
int pond[35][35];//,minextra=1000000000,minjump=1000000000,paths=0;

bool printvisit(bool arr[35][35],int y,int x){
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==y && j==x)
                cout<<"2 ";
            else
                cout<<arr[i][j]<<" ";
        }
        cout<<"  ";
        for(int j=0;j<n;j++){
            cout<<pond[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(bool visit[35][35],int cury,int curx,int extrapad,int jumpc){
    if(extrapad>minextra || (extrapad==minextra && jumpc>minjump))
        return;
    int newy,newx;
    for(int i=0;i<8;i++){
        newy=cury+dir[i][0];
        newx=curx+dir[i][1];
        if(newy>=0 && newy<m && newx>=0 && newx<n && pond[newy][newx]!=2 && visit[newy][newx]==0){
            //printvisit(visit,cury,curx);
            //if(extrapad>minextra || (extrapad==minextra && jumpc>minjump))
            //    return;
            if(pond[newy][newx]==0){ //&& !(extrapad+1>minextra || (extrapad+1==minextra && jumpc+1>minjump))){
                visit[newy][newx]=1;
                dfs(visit,newy,newx,extrapad+1,jumpc+1);
                visit[newy][newx]=0;
            }
            else if(pond[newy][newx]==1){ //&& !(extrapad>minextra || (extrapad==minextra && jumpc+1>minjump))){
                visit[newy][newx]=1;
                dfs(visit,newy,newx,extrapad,jumpc+1);
                visit[newy][newx]=0;
            }
            else if(pond[newy][newx]==4){
                jumpc++;
                if(extrapad==minextra){
                    if(jumpc<minjump){
                        minjump=jumpc;
                        paths=1;
                    }
                    else if(jumpc==minjump)
                        paths++;
                }
                else{
                    minextra=extrapad;
                    minjump=jumpc;
                    paths=1;
                }
                return;
            }
        }
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
        }
    }
    visitoriginal[starty][startx]=1;
    dfs(visitoriginal,starty,startx,0,0);
    if(minextra==1000000000)
        cout<<"-1"<<endl;
    else{
        cout<<minextra<<endl;
        cout<<minjump<<endl;
        cout<<paths<<endl;
    }
}






