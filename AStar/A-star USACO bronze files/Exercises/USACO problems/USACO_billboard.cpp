#include <iostream>
#include <stdio.h>
using namespace std;
                                //[0]  [1] [0]    [1]
int board[2][2][2];//board[board#][x or y][min or max]
int truck[2][2];   //        truck[x or y][min or max]
int overlapv[2];
int boardareas[2];

int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                cin>>board[i][k][j];
            }
        }
    }
    cin>>truck[0][0]>>truck[1][0]>>truck[0][1]>>truck[1][1];
    for(int i=0;i<2;i++){
        boardareas[i] = (board[i][0][1]-board[i][0][0]) * (board[i][1][1]-board[i][1][0]);
        bool intersect=true;
        for(int j=0;j<2;j++){
            if(board[i][j][0]>truck[j][1] || truck[j][0]>board[i][j][1])
                intersect=false;
        }
        if(intersect){
            for(int j=0;j<2;j++)
                overlapv[j]=min(board[i][j][1],truck[j][1])-max(board[i][j][0],truck[j][0]);
            boardareas[i]-=overlapv[0] * overlapv[1];
        }
    }
    cout<<boardareas[0]+boardareas[1]<<endl;
}
