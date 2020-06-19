#include <iostream>
#include <stdio.h>
using namespace std;

int n,k,cursize;
string boardinp[105];
string board[15];
bool checked[15][105];

void gravity(){
    string newline;
    for(int i=0;i<10;i++){
        newline="";
        for(int j=0;j<n;j++){
            if(board[i][j]!='0')
                newline+=board[i][j];
        }
        while(newline.size()<n)
            newline+='0';
        board[i]=newline;
    }
}

void checkregion(int cury,int curx){//x is 0 to n-1, y is 0 to 9
    if(curx+1<n && board[cury][curx+1]==board[cury][curx] && !checked[cury][curx+1]){
        cursize++;
        checked[cury][curx+1]=true;
        checkregion(cury,curx+1);
    }
    if(curx-1>=0 && board[cury][curx-1]==board[cury][curx] && !checked[cury][curx-1]){
        cursize++;
        checked[cury][curx-1]=true;
        checkregion(cury,curx-1);
    }
    if(cury+1<10 && board[cury+1][curx]==board[cury][curx] && !checked[cury+1][curx]){
        cursize++;
        checked[cury+1][curx]=true;
        checkregion(cury+1,curx);
    }
    if(cury-1>=0 && board[cury-1][curx]==board[cury][curx] && !checked[cury-1][curx]){
        cursize++;
        checked[cury-1][curx]=true;
        checkregion(cury-1,curx);
    }
}

void removeregion(){
    for(int i=0;i<10;i++){
        for(int j=0;j<n;j++){
            if(checked[i][j]==true){
                board[i][j]='0';
                checked[i][j]=false;
            }
        }
    }
}

void resetchecked(){
    for(int i=0;i<10;i++){
        for(int j=0;j<n;j++)
            checked[i][j]=false;
    }
}

void printboard(){
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<10;i++)
            cout<<board[i][j];
        cout<<endl;
    }
}

int main(){
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);
    string temp;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>boardinp[i];
    for(int i=0;i<10;i++){
        temp="";
        for(int j=n-1;j>=0;j--)
            temp+=boardinp[j][i];
        board[i]=temp;
    }
    bool finished=false;
    while(!finished){
        finished=true;
        for(int i=0;i<10;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='0'){
                    cursize=1;
                    checked[i][j]=true;
                    checkregion(i,j);
                    if(cursize>=k){
                        finished=false;
                        removeregion();
                    }
                    else
                        resetchecked();
                }
            }
        }
        gravity();
    }
    printboard();
}
