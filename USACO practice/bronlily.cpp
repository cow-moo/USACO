#include <iostream>
using namespace std;

int m,n,m1,m2,pond[35][35];
int dx[8],dy[8];

void bfs(){
}

int main(){
    cin>>m>>n>>m1>>m2;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>pond[i][j];
        }
    }
    dx = {-1*m1,-1*m1,m1,m1,-1*m2,-1*m2,m2,m2};
}
