#include <iostream>
#include <set>
#include <utility>
#include <stdio.h>
using namespace std;

//int x[50005],y[50005],r[50005],cowcount[50005];
//bool seen[50005];
//set<pair<int,int> > sight;
bool seen[1000050];
set<pair<pair<int,int>,int> > changepoints;//time,y-value,start/end
set<int> curseen;

int main(){
    //freopen("stampede.in","r",stdin);
    //freopen("stampede.out","w",stdout);
    /*int n,seecount=0;
    bool finished;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>r[i];
    }
    for(int t=0;;t++){
        finished=true;
        for(int i=0;i<n;i++){
            if(x[i]>=0)
                continue;
            finished=false;
            cowcount[i]++;
            if(cowcount[i]==r[i]){
                x[i]++;
                cowcount[i]=0;
            }
            if(x[i]==-1 && cowcount[i]==0)
                sight.insert(make_pair(y[i],i));
            else if(x[i]==0)
                sight.erase(make_pair(y[i],i));
        }
        if(finished)
            break;
        seen[(*sight.begin()).second]=true;
        cout<<t<<endl;
        for(int i=0;i<n;i++){
            cout<<x[i]<<" "<<cowcount[i]<<endl;
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        if(seen[i])
            seecount++;
    }
    cout<<seecount<<endl;*/
    int n,seencount=0,x,y,r,prev;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>r;
        changepoints.insert(make_pair(make_pair(r*(-1-x)-1,1),y));
        changepoints.insert(make_pair(make_pair(r*-x+1,0),y));
    }
    /*cout<<endl;
    cout<<(*changepoints.rbegin()).first.first<<" "<<(*changepoints.rbegin()).first.second<<" "<<(*changepoints.rbegin()).second<<endl;
    cout<<endl;*/
    for(set<pair<pair<int,int>,int> >::iterator it=changepoints.begin();it!=changepoints.end();++it){
        //cout<<(*it).first.first<<" "<<(*it).second;
        if((*it).first.second==1){
            curseen.insert((*it).second);
            //cout<<": "<<(*it).first.second<<endl;
        }
        else{
            curseen.erase((*it).second);
            //cout<<": "<<(*it).first.second<<endl;
        }
        /*for(set<int>::iterator it2=curseen.begin();it2!=curseen.end();++it2)
            cout<<*it2<<" ";
        cout<<endl;*/
        //cout<<*curseen.begin()<<endl;
        if(curseen.empty() || prev==(*it).first.first)
            continue;
        if(!seen[*curseen.begin()]){
            seencount++;
            seen[*curseen.begin()]=true;
        }
        prev=(*it).first.first;
        //cout<<(*it).first.first<<" "<<(*it).first.second<<" "<<(*it).second<<endl;
    }
    cout<<seencount<<endl;
}
