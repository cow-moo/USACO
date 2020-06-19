#include <iostream>
#include <stdio.h>
using namespace std;

string crosswords[55];

int main(){
    freopen("crosswords.in","r",stdin);
    freopen("crosswords.out","w",stdout);
    int n,m,counter=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>crosswords[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(crosswords[i][j]=='.' && (((i-1<0 || crosswords[i-1][j]=='#') && i+2<=n-1 && (crosswords[i+1][j]=='.' && crosswords[i+2][j]=='.')) || ((j-1<0 || crosswords[i][j-1]=='#') && j+2<=m-1 && (crosswords[i][j+1]=='.' && crosswords[i][j+2]=='.'))))
                counter++;
        }
    }
    cout<<counter<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(crosswords[i][j]=='.' && (((i-1<0 || crosswords[i-1][j]=='#') && i+2<=n-1 && (crosswords[i+1][j]=='.' && crosswords[i+2][j]=='.')) || ((j-1<0 || crosswords[i][j-1]=='#') && j+2<=m-1 && (crosswords[i][j+1]=='.' && crosswords[i][j+2]=='.'))))
                cout<<i+1<<" "<<j+1<<endl;
        }
    }
}
