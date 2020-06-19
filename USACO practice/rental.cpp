#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int cows[100050],rent[100050];
pair<int,int> store[100050];

int main(){
    freopen("rental.in","r",stdin);
    //freopen("rental.out","w",stdout);
    long long n,m,r,storemoney=0,rentmoney=0,totalgal=0,soldgal=0,curstore,maxim=0;
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        cin>>cows[i];
        totalgal+=cows[i];
    }
    for(int i=0;i<m;i++)
        cin>>store[i].second>>store[i].first;//cost then gallons
    for(int i=0;i<r;i++)
        cin>>rent[i];
    sort(cows,cows+n);
    sort(store,store+m,greater<pair<int,int> >());
    sort(rent,rent+r,greater<int>());
    //for(int i=1;i<r;i++)
    //    rent[i]+=rent[i-1];
    //cout<<totalgallons<<endl;
    soldgal=totalgal;
    for(int i=0;i<m;i++){
        if(soldgal==0)
            store[i].second=0;
        else if(soldgal-store[i].second>=0){
            curstore=i;
            storemoney+=store[i].second*store[i].first;
            soldgal-=store[i].second;
        }
        else{
            curstore=i;
            store[i].second=soldgal;
            storemoney+=store[i].second*store[i].first;
            soldgal=0;
        }
    }
    soldgal=totalgal-soldgal;
    //cout<<soldgal<<" "<<totalgal<<endl;
    //for(int i=0;i<m;i++)
    //    cout<<store[i].first<<" "<<store[i].second<<endl;
    //cout<<sold<<endl;
    for(int i=0;i<r;i++){//i is cow index
        if(i<n)
            rentmoney+=rent[i];
        if(totalgal-cows[i]>=soldgal){
            totalgal-=cows[i];
            continue;
        }
        if(totalgal-cows[i]<soldgal && totalgal>soldgal){
            cows[i]-=totalgal-soldgal;
            totalgal=soldgal;
        }
        for(;curstore>=0;curstore--){//j is curstore index
            if(cows[i]==store[curstore].second){
                storemoney-=store[curstore].second*store[curstore].first;
                store[curstore].second=0;
                cows[i]=0;
                curstore--;
                break;
            }
            else if(cows[i]<store[curstore].second){
                storemoney-=cows[i]*store[curstore].first;
                store[curstore].second-=cows[i];
                cows[i]=0;
                break;
            }
            else{
                storemoney-=store[curstore].second*store[curstore].first;
                cows[i]-=store[curstore].second;
                store[curstore].second=0;
                curstore--;
            }
        }
        if(storemoney+rentmoney>maxim)
            maxim=storemoney+rentmoney;
    }
    cout<<maxim<<endl;
}
