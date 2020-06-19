#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

pair<int,int> xh[50005];
multiset<int> lw,rw;

int main(){
    int n,d,ri=0,li=0,counter=0;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>xh[i].first>>xh[i].second;
    sort(xh,xh+n);
    rw.insert(0);
    lw.insert(0);
    for(int i=0;i<n;i++){
        while(xh[ri].first-xh[i].first<=d && ri<n)
            rw.insert(xh[ri++].second);
        while(xh[i].first-xh[li].first>d)
            lw.erase(xh[li++].second);
        rw.erase(xh[i].second);
        if(*rw.rbegin()>=2*xh[i].second && *lw.rbegin()>=2*xh[i].second)
            counter++;
        lw.insert(xh[i].second);
    }
    cout<<counter<<endl;
}
