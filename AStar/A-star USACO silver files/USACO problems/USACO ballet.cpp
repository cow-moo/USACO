#include <iostream>
using namespace std;
/*
0: FR
1: FL
2: RR
3: RL
*/
//       foot#  x or y
int feetpos[5][2],direction[2],minx=1000000,maxx=-1000000,miny=1000000,maxy=-1000000;
string feet[4]={"FR","FL","RR","RL"};
bool trip=false;

void movement(int foot,int dx,int dy){
    feetpos[foot][0]+=dy*direction[0]+dx*direction[1];
    feetpos[foot][1]+=dy*direction[1]-dx*direction[0];
    for(int i=0;i<4;i++){
        if(foot!=i && feetpos[foot][0]==feetpos[i][0] && feetpos[foot][1]==feetpos[i][1])
            trip=true;
    }
}

void rotation(int pfoot){
    for(int i=0;i<4;i++){
        if(i==pfoot)
            continue;
        int temp0 = feetpos[i][0];
        feetpos[i][0]=feetpos[pfoot][0]-(feetpos[pfoot][1]-feetpos[i][1]);
        feetpos[i][1]=feetpos[pfoot][1]+(feetpos[pfoot][0]-temp0);
    }
    if(direction[0]!=0){
        direction[1]=direction[0]*-1;
        direction[0]=0;
    }
    else{
        direction[0]=direction[1];
        direction[1]=0;
    }
}

int main(){
    feetpos[0][0]=1; feetpos[0][1]=1;
    feetpos[1][1]=1;
    feetpos[2][0]=1;
    direction[1]=1;
    int n,tempfoot;
    string input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        for(int j=0;j<4;j++){
            if(input.substr(0,2)==feet[j])
                tempfoot=j;
        }
        if(input[2]=='F')
            movement(tempfoot,0,1);
        else if(input[2]=='B')
            movement(tempfoot,0,-1);
        else if(input[2]=='R')
            movement(tempfoot,1,0);
        else if(input[2]=='L')
            movement(tempfoot,-1,0);
        else{
            rotation(tempfoot);
        }
        for(int j=0;j<4;j++){
            if(feetpos[j][0]>maxx)
                maxx=feetpos[j][0];
            if(feetpos[j][0]<minx)
                minx=feetpos[j][0];
            if(feetpos[j][1]>maxy)
                maxy=feetpos[j][1];
            if(feetpos[j][1]<miny)
                miny=feetpos[j][1];
        }
    }
    if(trip)
        cout<<-1<<endl;
    else{
        cout<<(maxx-minx+1)*(maxy-miny+1)<<endl;
    }
}
