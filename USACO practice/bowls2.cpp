#include <iostream>
using namespace std;

void solve(){
    int counter=0,ans=25;
    bool bowls[25],temp,origb[25];
    for(int i=0;i<20;i++){
        cin>>bowls[i];
        origb[i]=bowls[i];
    }
    for(int i=0;i<(1<<20);i++){
        counter=0;
        for(int j=0;j<20;j++){
            if(((i>>j)%2)==0)
                continue;
            else
                counter++;
            for(int k=-1;k<=1;k++){
                if(j>=0 && j<20){
                    bowls[j+k]=1-bowls[j+k];
                }
            }
        }
        if(counter<ans){
            temp=true;
            for(int j=0;j<20;j++){
                if(bowls[j]==1){
                    temp=false;
                    break;
                }
            }
            if(temp)
                ans=counter;
        }
        for(int j=0;j<20;j++){
            bowls[j]=origb[j];
        }
    }
    cout<<ans<<endl;
}

int main(){
    solve();
}
