#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<pair<int,int>,int> parts[10005];
vector<int> ans;

bool compare(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.first.first*b.first.second==a.first.second*b.first.first){
        if(a.first.second>b.first.second)
            return true;
        else
            return false;
    }
    else if(a.first.first*b.first.second>a.first.second*b.first.first)
        return true;
    else
        return false;
}

int main(){
    int f,m,n;
    cin>>f>>m>>n;
    for(int i=0;i<n;i++){
        cin>>parts[i].first.first>>parts[i].first.second;
        parts[i].second=i;
    }
    sort(parts,parts+n,compare);
    for(int i=0;i<n;i++){
        if(parts[i].first.first*m>f*parts[i].first.second){
            ans.push_back(parts[i].second);
            f+=parts[i].first.first;
            m+=parts[i].first.second;
        }
        else
            break;
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]+1<<endl;
    if(ans.size()==0)
        cout<<"NONE"<<endl;
}
