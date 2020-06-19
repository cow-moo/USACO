#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

pair<pair<int,int>,pair<int,int> > cpoints[100005];
set<pair<int,int> > curbox;
pair<int,int> temp;
int n;

bool enclose(int y1b,int y1t,int y2b,int y2t){
    if(y1t>y2t && y1b<y2b)
        return true;
    else
        return false;
}

int main(){
    int input,inputarr[4],counter=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cpoints[2*i].first.first>>cpoints[2*i].second.first>>cpoints[2*i+1].first.first>>cpoints[2*i].second.second;
        cpoints[2*i].first.second=0;
        cpoints[2*i+1].second.first=cpoints[2*i].second.first;
        cpoints[2*i+1].second.second=cpoints[2*i].second.second;
        cpoints[2*i+1].first.second=1;
    }
    bool isenclosed;
    sort(cpoints,cpoints+2*n);
    for(int i=0;i<2*n;i++){
        if(cpoints[i].first.second==0){
            isenclosed=false;
            for(set<pair<int,int> >::iterator j=curbox.begin();j!=curbox.end();j++){
                if(enclose((*j).first,(*j).second,cpoints[i].second.first,cpoints[i].second.second)){
                    isenclosed=true;
                    break;
                }
            }
            if(!isenclosed){
                counter++;
                curbox.insert(make_pair(cpoints[i].second.first,cpoints[i].second.second));
            }
        }
        else{
            curbox.erase(make_pair(cpoints[i].second.first,cpoints[i].second.second));
        }
    }
    cout<<counter<<endl;
}
