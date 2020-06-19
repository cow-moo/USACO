#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> stations[50005];

int main(){
    int n,g,gas,d,minim,minindex,position;
    long long cost=0;
    cin>>n>>g>>gas>>d;
    for(int i=0;i<n;i++){
        cin>>stations[i].first>>stations[i].second;
    }
    stations[n].first=d;
    stations[n].second=0;
    sort(stations,stations+n);
    minim=1000000000;
    for(position=0;;position++){
        if(stations[position].first>gas)
            break;
        if(stations[position].second<minim){
            minim=stations[position].second;
            minindex=position;
        }
    }
    gas-=stations[minindex].first;
    position=minindex;
    while(position<n){
        minim=1000000000;
        for(int i=1;;i++){
            if(stations[position+i].first-stations[position].first>g || position+i>n)
                break;
            if(stations[position+i].second<=minim){
                minim=stations[position+i].second;
                minindex=position+i;
            }
        }
        if(minim==1000000000){
            cost=-1;
            break;
        }
        if(minim<stations[position].second){
            cost+=(stations[minindex].first-stations[position].first-gas)*stations[position].second;//gas needed minus curgas
            gas=0;
        }
        else{
            cost+=(g-gas)*stations[position].second;
            gas=g-(stations[minindex].first-stations[position].first);
        }
        position=minindex;
    }
    //if(gas<(d-position[n-1].first))
    //    cost+=d-position[n-1].fi
    cout<<cost<<endl;
}
