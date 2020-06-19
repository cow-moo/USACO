#include <iostream>
#include <sstream>
using namespace std;

int n,dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}},nextdir[4][2]={{1,3},{0,2},{1,3},{0,2}},maxim=0;
bool visited[125][125];
short grid[125][125];  //0 is nothing, 1 is visited, 2 is barrier

void printboard(){
    /*for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            cout<<grid[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
}

void revertmove(int curp[],int diri,int movecount){
    //cout<<"spaghett"<<endl;
    for(int i=0;i<=movecount;i++){
        grid[curp[0]][curp[1]]=0;
        curp[0]+=dir[diri][0];
        curp[1]+=dir[diri][1];
        //cout<<curp[0]<<" "<<curp[1]<<endl;
    }
}

int movement(int curp[],int diri){
    int movecount=0;
    do{
        grid[curp[0]][curp[1]]=1;
        curp[0]+=dir[diri][0];
        curp[1]+=dir[diri][1];
        movecount++;
    }while(grid[curp[0]][curp[1]]==0);
    if(grid[curp[0]][curp[1]]==1)
        return 1-movecount;
    else
        return movecount-1;
}


void recurse(int curx,int cury,int dist,int givendir){
    //visited[curx][cury]=1;
    if(dist>maxim)
        maxim=dist;
    printboard();
    int tempp[2]={curx,cury};
    int tempdist = movement(tempp,givendir);
    if(tempdist==0){
        return;
    }
    //cout<<tempdist<<endl;
    tempp[0]=curx;
    tempp[1]=cury;
    if(tempdist<0){
        dist+=tempdist * -1;
        if(dist>maxim)
            maxim=dist;
        //cout<<"asdf"<<endl;
        revertmove(tempp,givendir,tempdist*-1);
        return;
    }
    else{
        dist+=tempdist;
        recurse(curx+tempdist*dir[givendir][0],cury+tempdist*dir[givendir][1],dist,nextdir[givendir][0]);
        recurse(curx+tempdist*dir[givendir][0],cury+tempdist*dir[givendir][1],dist,nextdir[givendir][1]);
    }
    //cout<<curx<<" "<<tempp[0]<<endl;
    revertmove(tempp,givendir,tempdist);
}

int main(){
    int b;
    string tempb;
    int temp1,temp2,tempe;
    cin>>n>>b;
    for(int i=0;i<b;i++){
        cin>>tempb;
        temp1=tempb[0]-'A';
        tempb.erase(0,1);
        stringstream temp(tempb);
        temp>>temp2;
        grid[temp1+1][temp2]=2;
    }
    for(int i=0;i<=n+1;i++){
        grid[0][i]=2;
        grid[i][0]=2;
        grid[n+1][i]=2;
        grid[i][n+1]=2;
    }
    /*int temp[2];
    temp[0]=1; temp[1]=1;
    int tempx=movement(temp,0);
    printboard();
    //cout<<temp[0]<<" "<<temp[1]<<" asdf"<<endl;
    temp[0]=1; temp[1]=1;
    revertmove(temp,0,tempx);
    printboard();*/
    recurse(1,1,0,0);
    recurse(1,1,0,1);
    cout<<maxim+1<<endl;
}
