#include <iostream>
#include <stdio.h>
#include <utility>
using namespace std;

pair<int,int> cows[100005];
bool gone[100005];

int main(){
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    int n,curt=0,maxwait=0,mint,mincow;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cows[i].first>>cows[i].second;
    }
    bool line,done=false;
    while(!done){
        line=false;
        done=true;
        mint=1000000000;
        for(int i=0;i<n;i++){
            if(!gone[i])
                done=false;
            if(curt>=cows[i].first && !gone[i]){
                if(curt-cows[i].first>maxwait)
                    maxwait=curt-cows[i].first;
                curt+=cows[i].second;
                gone[i]=true;
                line=true;
            }
            if(cows[i].first<mint && !gone[i]){
                mint=cows[i].first;
                mincow=i;
            }
        }
        if(!line){
            curt=cows[mincow].first+cows[mincow].second;
            gone[mincow]=true;
        }
    }
    cout<<maxwait<<endl;
}
