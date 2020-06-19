#include <iostream>
using namespace std;

string maze[45];
int main(){
    int n,m,movecount=0,px,py;
    string moves;
    bool win=false;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>maze[i];
        for(int j=0;j<m;j++){
            if(maze[i][j]=='S'){
                px=j;
                py=i;
                maze[i][j]='P';
            }
        }
    }
    cin>>moves;
    for(int i=0;i<moves.length();i++){
        cout<<"Your move: "<<moves[i]<<endl;
        if(moves[i]=='U'){
            if(maze[py-1][px]=='.'){
                swap(maze[py][px],maze[py--][px]);
                movecount++;
            }
            else if(maze[py-1][px]=='E'){
                maze[py][px]='.';
                maze[--py][px]='P';
                win=true;
                movecount++;
            }
            else
                cout<<"Invalid move!"<<endl;
        }
        if(moves[i]=='D'){
            if(maze[py+1][px]=='.'){
                swap(maze[py][px],maze[py++][px]);
                movecount++;
            }
            else if(maze[py+1][px]=='E'){
                maze[py][px]='.';
                maze[++py][px]='P';
                win=true;
                movecount++;
            }
            else
                cout<<"Invalid move!"<<endl;
        }
        if(moves[i]=='L'){
            if(maze[py][px-1]=='.'){
                swap(maze[py][px],maze[py][px--]);
                movecount++;
            }
            else if(maze[py][px-1]=='E'){
                maze[py][px]='.';
                maze[py][--px]='P';
                win=true;
                movecount++;
            }
            else
                cout<<"Invalid move!"<<endl;
        }
        if(moves[i]=='R'){
            if(maze[py][px+1]=='.'){
                swap(maze[py][px],maze[py][px++]);
                movecount++;
            }
            else if(maze[py][px+1]=='E'){
                maze[py][px]='.';
                maze[py][px++]='P';
                win=true;
                movecount++;
            }
            else
                cout<<"Invalid move!"<<endl;
        }
        cout<<"Number of moves: "<<movecount<<endl;
        for(int j=0;j<n;j++)
            cout<<maze[j]<<endl;
        cout<<endl;
        if(win){
            cout<<"Congratulations you found the exit!"<<endl;
            break;
        }
    }
}
