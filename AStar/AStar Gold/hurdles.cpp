#include <iostream>
#include <algorithm>
using namespace std;

int d[305][305];

int main(){
    int n,m,t,inp1,inp2,inp3;
    cin>>n>>m>>t;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            d[i][j]=2000000;
        }
    }
    for(int i=0;i<m;i++){
        cin>>inp1>>inp2>>inp3;
        d[inp1][inp2]=inp3;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
            }
        }
    }
    for(int i=0;i<t;i++){
        cin>>inp1>>inp2;
        if(d[inp1][inp2]==2000000)
            cout<<-1<<endl;
        else
            cout<<d[inp1][inp2]<<endl;
    }
}
