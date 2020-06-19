#include <iostream>
using namespace std;

int dir[4][2]={{1,0},{0,1},{1,1},{1,-1}},curx,cury,n;
int matrix[205][205],maxim=-1000000000;

void wrap(){
    if(curx>=n)
        curx-=n;
    else if(curx<0)
        curx+=n;
    if(cury>=n)
        cury-=n;
    else if(cury<0)
        cury+=n;
}

void summation(int direction){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=matrix[curx][cury];
        if(sum>maxim)
            maxim=sum;
        curx+=dir[direction][0];
        cury+=dir[direction][1];
        wrap();
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                curx=i; cury=j;
                summation(k);
            }
        }
    }
    cout<<maxim<<endl;
}
