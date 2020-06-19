#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,bales[25][2],height=0,ans=0,temp[25],tempcount=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>bales[i][0]>>bales[i][1];
        temp[i]=bales[i][0];
    }
    sort(temp,temp+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(bales[j][0]==temp[i]){
                swap(bales[j][0],bales[i][0]);
                swap(bales[j][1],bales[i][1]);
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        height=0;
        for(int j=0;j<n;j++){
            if(((i>>j)%2)>0){
                temp[height++]=bales[j][1];
            }
        }
        bool temp2=true;
        for(int j=0;j<height-1;j++){
            if(temp[j]>=temp[j+1])
                temp2=false;
        }
        if(temp2 && height>ans){
            ans=height;
        }
    }
    cout<<ans<<endl;
}

int main(){
    solve();
}
