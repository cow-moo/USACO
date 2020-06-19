#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int pfx[100005],n;
pair<int,int> line[100005];

void update(int x,int v){
    while(x<=n){
        pfx[x]+=v;
        x+=(x&(-x));
    }
}

int query(int x){
    int ans=0;
    while(x>0){
        ans+=pfx[x];
        x-=(x&(-x));
    }
    return ans;
}

bool compare(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}

int main(){
    int answer=0,lside,rside;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>line[i].first;
        line[i].second=i;
    }
    sort(line,line+n,compare);
    for(int i=0;i<n;i++){
        lside=query(line[i].second+1);
        rside=i-lside;
        if(lside>2*rside || rside>2*lside)
            answer++;
        update(line[i].second+1,1);
    }
    cout<<answer<<endl;
}
