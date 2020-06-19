#include <iostream>
using namespace std;

string integers[100000];
int anscount=0;
char grid[10][10];

void recurse(int hops,string curint,int x,int y){
    int temphops=hops;
    string tempint=curint;
    int tempx=x;
    int tempy=y;
    if(hops==0){
        for(int i=0;i<anscount;i++){
            if(integers[i]==curint)
                return;
        }
        integers[anscount++]=curint;
        return;
    }
    if(x+1<=4){
        curint+=grid[x+1][y];
        recurse(hops-1,curint,x+1,y);
    }
    if(x-1>=0){
        hops=temphops; curint=tempint; x=tempx; y=tempy;
        curint+=grid[x-1][y];
        recurse(hops-1,curint,x-1,y);
    }
    if(y+1<=4){
        hops=temphops; curint=tempint; x=tempx; y=tempy;
        curint+=grid[x][y+1];
        recurse(hops-1,curint,x,y+1);
    }
    if(y-1>=0){
        hops=temphops; curint=tempint; x=tempx; y=tempy;
        curint+=grid[x][y-1];
        recurse(hops-1,curint,x,y-1);
    }
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            recurse(5,string(1,grid[i][j]),i,j);
        }
    }
    cout<<anscount<<endl;
}
