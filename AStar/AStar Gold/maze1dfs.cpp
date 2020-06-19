#include <iostream>
using namespace std;


string maze[105]; //height then width
int w,h;
int exitp[2][2];
int dist[105][40][2],dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool canmove(int beginh,int beginw,int diri,int x){
    if(maze[2*beginh+1+dir[diri][0]][2*beginw+1+dir[diri][1]]==' ' && dist[beginh+dir[diri][0]][beginw+dir[diri][1]][x]==0 && beginh+dir[diri][0]>=0 && beginh+dir[diri][0]<h && beginw+dir[diri][1]>=0 && beginw+dir[diri][1]<w)
        return true;
    else
        return false;
}

void recurse(int curh,int curw,int exitnum,int tempdist){
    dist[curh][curw][exitnum]=tempdist;
    for(int i=0;i<4;i++){
        if(canmove(curh,curw,i,exitnum)){
            recurse(curh+dir[i][0],curw+dir[i][1],exitnum,tempdist+1);
        }
    }
}

int main(){
    cin>>w>>h;
    string temp;
    getline(cin,temp);
    for(int i=0;i<2*h+1;i++){
        getline(cin,maze[i]);
    }
    int exitcount=0;
    for(int i=0;i<w;i++){
        if(maze[0][2*i+1]==' '){
            exitp[exitcount][0]=0;
            exitp[exitcount++][1]=i;
        }
        if(maze[2*h][2*i+1]==' '){
            exitp[exitcount][0]=h-1;
            exitp[exitcount++][1]=i;
        }
    }
    for(int i=0;i<h;i++){
        if(maze[2*i+1][0]==' '){
            exitp[exitcount][0]=i;
            exitp[exitcount++][1]=0;
        }
        if(maze[2*i+1][2*w]==' '){
            exitp[exitcount][0]=i;
            exitp[exitcount++][1]=w-1;
        }
    }
    recurse(exitp[0][0],exitp[0][1],0,1);
    recurse(exitp[1][0],exitp[1][1],1,1);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i][j][0]=min(dist[i][j][0],dist[i][j][1]);
            //cout<<dist[i][j][0]<<" ";
        }
        //cout<<endl;
    }
    int maxim=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(dist[i][j][0]>maxim)
                maxim=dist[i][j][0];
        }
    }
    cout<<maxim<<endl;
}
