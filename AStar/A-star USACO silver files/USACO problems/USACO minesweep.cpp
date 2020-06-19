#include <iostream>
using namespace std;

int n,m,grid[35][35],coords[905][2],totalmines;
bool finished = false;

void recurse(int mines,int x,int y){
    if(finished)
        return;
    bool temp=true;
    if(mines==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    temp=false;
                    return;
                }
            }
        }
        if(temp)
            finished=true;
        return;
    }
    for(int i=x+1;i<m;i++){
        temp=true;
        for(int j=-1;j<=1;j++){
            for(int k=-1;k<=1;k++){
                if(i+j<m && i+j>=0 && y+k<n && y+k>=0 && grid[y+k][i+j]==0){
                    temp=false;
                    break;
                }
            }
            if(!temp)
                break;
        }
        if(temp){
            for(int j=-1;j<=1;j++){
                for(int k=-1;k<=1;k++){
                    if(i+j<m && i+j>=0 && y+k<n && y+k>=0){
                        grid[y+k][i+j]--;
                    }
                }
            }
            coords[totalmines-mines][0]=i; coords[totalmines-mines][1]=y;
            recurse(mines-1,i,y);
            for(int j=-1;j<=1;j++){
                for(int k=-1;k<=1;k++){
                    if(i+j<m && i+j>=0 && y+k<n && y+k>=0){
                        grid[y+k][i+j]++;
                    }
                }
            }
            if(finished)
                return;
        }
    }
    for(int h=y+1;h<n;h++){
        for(int i=0;i<m;i++){
            bool temp=true;
            for(int j=-1;j<=1;j++){
                for(int k=-1;k<=1;k++){
                    if(i+j<m && i+j>=0 && h+k<n && h+k>=0 && grid[h+k][i+j]==0){
                        temp=false;
                        break;
                    }
                }
                if(!temp)
                    break;
            }
            if(temp){
                for(int j=-1;j<=1;j++){
                    for(int k=-1;k<=1;k++){
                        if(i+j<m && i+j>=0 && h+k<n && h+k>=0){
                            grid[h+k][i+j]--;
                        }
                    }
                }
                coords[totalmines-mines][0]=i; coords[totalmines-mines][1]=h;
                recurse(mines-1,i,h);
                for(int j=-1;j<=1;j++){
                    for(int k=-1;k<=1;k++){
                        if(i+j<m && i+j>=0 && h+k<n && i+j>=0){
                            grid[h+k][i+j]++;
                        }
                    }
                }
                if(finished)
                    return;
            }
        }
    }
}

int main(){
    cin>>n>>m>>totalmines;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    recurse(totalmines,-1,0);
    if(finished){
        for(int i=0;i<totalmines;i++){
            cout<<coords[i][1]+1<<" "<<coords[i][0]+1<<endl;
        }
    }
}
