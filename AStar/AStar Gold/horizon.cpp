#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
using namespace std;

int a[40005],b[40005],h[40005];
pair<pair<int,int>,int> buildings[40005];

int overlap(int build1,int build2){
    if(buildings[build2].first.second>buildings[build1].first.first && buildings[build1].first.second>buildings[build2].first.first){
        if(buildings[build2].first.second<=buildings[build1].first.second)
            return 2;
        else
            return 1;
    }
    else
        return false;
}

int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>buildings[i].first.first>>buildings[i].first.second>>buildings[i].second;
        sum+=(buildings[i].first.second-buildings[i].first.first)*buildings[i].second;
    }
    sort(buildings,buildings+n);
    /*cout<<endl;
    for(int i=0;i<n;i++){
        cout<<buildings[i].first.first<<" "<<buildings[i].first.second<<" "<<buildings[i].second<<endl;
    }*/
    int tempover;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            tempover=overlap(i,j);
            if(tempover==1){
                //cout<<i<<" "<<j<<endl;
                sum-=min(buildings[i].second,buildings[j].second)*(buildings[i].first.second-buildings[j].first.first);
            }
            else if(tempover==2){
                sum-=buildings[j].second*(buildings[j].first.second-buildings[j].first.first);
            }
            else
                break;
        }
    }
    cout<<sum<<endl;
}
