#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int checkpoints[100050][2];

int main(){
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    int n,diff,maxdiff=0,totaldist=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>checkpoints[i][0]>>checkpoints[i][1];
        if(i>0)
            totaldist+=abs(checkpoints[i][0]-checkpoints[i-1][0]) + abs(checkpoints[i][1]-checkpoints[i-1][1]);
    }
    for(int i=1;i<n-1;i++){
        maxdiff=max(maxdiff,(abs(checkpoints[i-1][0]-checkpoints[i][0]) + abs(checkpoints[i-1][1]-checkpoints[i][1]) + abs(checkpoints[i][0]-checkpoints[i+1][0]) + abs(checkpoints[i][1]-checkpoints[i+1][1])) - (abs(checkpoints[i-1][0]-checkpoints[i+1][0]) + abs(checkpoints[i-1][1]-checkpoints[i+1][1])));
    }
    cout<<totaldist-maxdiff<<endl;
}
