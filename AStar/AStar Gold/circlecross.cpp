#include <iostream>
#include <vector>
using namespace std;

pair<int,bool> crossing[100005];//cow id,start or end
bool alreadycross[100005];
vector<int> curcows;

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>crossing[i].first;
        if(alreadycross[crossing[i].first])
            crossing[i].second=true;
        else{
            alreadycross[crossing[i].first]=true;
            crossing[i].second=false;
        }
    }
    for(int i=0;i<2*n;i++){
        if(!crossing[i].second)
            curcows.push_back(crossing[i].first);
        else{
            for(int j=0;j<curcows.size();j++){
                if(curcows[j]==crossing[i].first){
                    ans+=curcows.size()-j-1;
                    curcows.erase(curcows.begin()+j);
                }
            }
        }
    }
    cout<<ans<<endl;
}
