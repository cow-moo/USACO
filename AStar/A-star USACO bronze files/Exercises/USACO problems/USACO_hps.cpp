#include <iostream>
#include <stdio.h>
using namespace std;

short games[105][2],wins[2];

int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>games[i][0]>>games[i][1];
    for(int i=-1;i<=1;i+=2){
        for(int j=0;j<n;j++){
            if((games[j][0]+i)%3==(games[j][1])%3)
                wins[(i+1)/2]++;
        }
    }
    cout<<max(wins[0],wins[1])<<endl;
}
