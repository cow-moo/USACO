#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

pair<pair<int,int>,int> points[80005];//0 is start, 1 is end
multiset<int> curh;
//<<pos,h>,st/end>
int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>points[2*i].first.first>>points[2*i+1].first.first>>points[2*i].first.second;
        points[2*i+1].first.second = points[2*i].first.second;
        points[2*i].second = 0;
        points[2*i+1].second = 1;
    }
    sort(points,points+2*n);
    /*for(int i=0;i<2*n;i++)
        cout<<points[i].first.first<<endl;*/
    for(int i=0;i<2*n-1;i++){
        if(points[i].second==0){
            curh.insert(points[i].first.second);
        }
        else{
            curh.erase(curh.find(points[i].first.second));
        }
        if(!curh.empty())
            sum+=*curh.rbegin() * (points[i+1].first.first-points[i].first.first);
    }
    cout<<sum<<endl;
}
