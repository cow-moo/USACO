#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> jobs[1005];

int main(){
    int n,curt=1000000;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>jobs[i].second>>jobs[i].first;//first:deadline,second:time
    sort(jobs,jobs+n);
    for(int i=n-1;i>=0;i--){
        if(curt>jobs[i].first)
            curt=jobs[i].first;
        curt-=jobs[i].second;
    }
    if(curt<0)
        curt=-1;
    cout<<curt<<endl;
}
