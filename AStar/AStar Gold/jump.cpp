#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int rocks[50005];
bool taken[50005];
priority_queue<pair<int,pair<int,int> > > distances;

int main(){
    int l,n,m;
    pair<int,pair<int,int> > minim;
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>rocks[i];
    rocks[0]=0;
    rocks[n+1]=l;
    sort(rocks,rocks+n+2);
    for(int i=0;i<=n;i++)
        distances.push(make_pair((rocks[i+1]-rocks[i])*-1,make_pair(i,i+1)));
    //taken[0]=true;
    //taken[n+1]=true;
    for(int i=0;i<m;i++){
        minim=distances.top();
        minim.first*=-1;
        distances.pop();
        if(taken[minim.second.first] || taken[minim.second.second])
            continue;
        if(!taken[minim.second.first] && !taken[minim.second.second]){
            if((rocks[minim.second.second+1]-rocks[minim.second.second])>(rocks[minim.second.first]-rocks[minim.second.first-1]) || minim.second.first==0){
                distances.push(make_pair((rocks[minim.second.second+1]-rocks[minim.second.first])*-1,make_pair(minim.second.first,minim.second.second+1)));
                taken[minim.second.second]=true;
            }
            else{
                distances.push(make_pair((rocks[minim.second.second]-rocks[minim.second.first-1])*-1,make_pair(minim.second.first-1,minim.second.second)));
                taken[minim.second.first]=true;
            }
        }
        /*else if(taken[minim.second.first]){
            distances.push(make_pair((rocks[minim.second.second+1]-rocks[minim.second.first])*-1,make_pair(minim.second.first,minim.second.second+1)));
            taken[minim.second.second]=true;
        }
        else if(taken[minim.second.second]){
            distances.push(make_pair((rocks[minim.second.second]-rocks[minim.second.first-1])*-1,make_pair(minim.second.first-1,minim.second.second)));
            taken[minim.second.first]=true;
        }*/
    }
    while(1){
        minim=distances.top();
        minim.first*=-1;
        distances.pop();
        if((!taken[minim.second.first]||minim.second.first==0) && (!taken[minim.second.first]||minim.second.second==n+1)){
            cout<<distances.top().first*-1<<endl;
            break;
        }
    }
}
/*
25 5 2
2
14
11
21
17
*/
