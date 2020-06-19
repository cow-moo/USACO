#include <iostream>
using namespace std;

int r,c,maxl,temp[25][2],ans=0,dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool forest[6][6];

void recurse(int length,int path[25][2]){
    int curx=path[length-1][0];
    int cury=path[length-1][1];
    int i,j;
    for(int a=0;a<4;a++){
        i=dir[a][0];
        j=dir[a][1];
        if(curx+i>=0 && curx+i<r && cury+j>=0 && cury+j<c && forest[curx+i][cury+j]==0){
            bool temp=true;
            for(int k=0;k<length;k++){
                if((curx+i)==path[k][0] && (cury+j)==path[k][1]){
                    temp=false;
                    break;
                }
            }
            if(temp && length<maxl){
                if(curx+i==r-1 && cury+j==c-1){
                    ans++;
                }
                path[length][0]=curx+i;
                path[length][1]=cury+j;
                recurse(length+1,path);
                curx=path[length-1][0];
                cury=path[length-1][1];
            }
        }
    }
}

int main(){
    cin>>r>>c>>maxl;
    string input;
    for(int i=0;i<r;i++){
        cin>>input;
        for(int j=0;j<c;j++){
            if(input[j]=='T'){
                forest[r-i-1][j]=1;
            }
        }
    }
    recurse(1,temp);
    cout<<ans<<endl;
}
