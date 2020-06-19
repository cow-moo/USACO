#include <iostream>
using namespace std;

pair<int,int> bales[50005];

int main(){
    int n,minx=1000000,miny=1000000;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>bales[i].first>>bales[i].second;
        if(bales[i].first<minx)
            minx=bales[i].first;
        if(bales[i].second<miny)
            miny=bales[i].second;
    }
    for(int i=0;i<n;i++){
        bales[i].first-=minx;
        bales[i].second-=miny;
        cout<<bales[i].first<<" "<<bales[i].second<<endl;
    }
}
