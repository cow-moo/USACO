#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

pair<int,int> peaks;
vector<pair<pair<int,int>,bool> > changepts;//x,y,up/down
multiset<int> curup;//beginning of up
multiset<int> curdown;//ending of down

int main(){
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    int n,inpx,inpy,curx,cury,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inpx>>inpy;
        changepts.push_back(make_pair(make_pair(inpx-inpy,0),1));
        changepts.push_back(make_pair(make_pair(inpx,inpy),0));
    }
    sort(changepts.begin(),changepts.end());
    for(vector<pair<pair<int,int>,bool> >::iterator it=changepts.begin();it!=changepts.end();++it){
        curx=(*it).first.first;
        cury=(*it).first.second;
        if((*it).second)
            curup.insert(curx);
        else{
            curup.erase(curup.find(curx-cury));
            if((curup.size()==0 || (curx-*curup.begin())<cury) && (curdown.size()==0 || (*curdown.rbegin()-curx)<cury))
                ans++;
            curdown.insert(curx+cury);
        }
    }
    cout<<ans<<endl;
}
