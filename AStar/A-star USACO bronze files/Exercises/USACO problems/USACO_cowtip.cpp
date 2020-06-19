#include <iostream>
#include <stdio.h>
using namespace std;

bool cows[15][15];

void flip(int x,int y){
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            cows[i][j] = 1-cows[i][j];
        }
    }
}

int main(){
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    int fcount=0,n;
    string input;
    bool cont=true;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        for(int j=0;j<n;j++){
            cows[i][j] = input[j]-'0';
        }
    }
    while(cont){
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(cows[i][j]){
                    flip(i,j);
                    fcount++;
                }
            }
        }
        cont=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cows[i][j]){
                    cont=true;
                    break;
                }
            }
            if(cont)
                break;
        }
    }
    cout<<fcount<<endl;
}
