#include <iostream>
using namespace std;

int n,c,coins[10][2],counter,cursum;

int main(){
    cin>>n>>c;
    for(int i=0;i<c;i++){
        cin>>coins[i][0];
    }
    bool notdone=true;
    while(notdone){
        for(int i=c-2;i>=-1;i--){
            if(i==-1){
                notdone=false;
            }
            else if(n-cursum<coins[i][0]){
                cursum-=coins[i][0]*coins[i][1];
                coins[i][1]=0;
            }
            else{
                cursum+=coins[i][0];
                coins[i][1]++;
                break;
            }
        }
        if((n-cursum)%coins[c-1][0]==0){
            counter++;
        }
    }
    cout<<counter<<endl;
}
