#include <iostream>
#include <stdio.h>
using namespace std;

int n,curblob=2,cursize,curperim;
pair<int,int> maxblob;//size,perim
int icecream[1005][1005];

void checkregion(int cury,int curx){
    int pointperim=0;
    if(curx+1>=n || icecream[cury][curx+1]==0)
        pointperim++;
    if(curx-1<0 || icecream[cury][curx-1]==0)
        pointperim++;
    if(cury+1>=n || icecream[cury+1][curx]==0)
        pointperim++;
    if(cury-1<0 || icecream[cury-1][curx]==0)
        pointperim++;
    curperim+=pointperim;
    if(curx+1<n && icecream[cury][curx+1]==1){
        cursize++;
        icecream[cury][curx+1]=curblob;
        checkregion(cury,curx+1);
    }
    if(curx-1>=0 && icecream[cury][curx-1]==1){
        cursize++;
        icecream[cury][curx-1]=curblob;
        checkregion(cury,curx-1);
    }
    if(cury+1<n && icecream[cury+1][curx]==1){
        cursize++;
        icecream[cury+1][curx]=curblob;
        checkregion(cury+1,curx);
    }
    if(cury-1>=0 && icecream[cury-1][curx]==1){
        cursize++;
        icecream[cury-1][curx]=curblob;
        checkregion(cury-1,curx);
    }
}

int main(){
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    string input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        for(int j=0;j<n;j++)
            icecream[i][j]=input[j]=='#';
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(icecream[i][j]==1){
                cursize=1;
                curperim=0;
                icecream[i][j]=curblob;
                checkregion(i,j);
                if(cursize>maxblob.first || (cursize==maxblob.first && curperim<maxblob.second)){
                    maxblob.first=cursize;
                    maxblob.second=curperim;
                }
                curblob++;
            }
        }
    }
    cout<<maxblob.first<<" "<<maxblob.second<<endl;
}
