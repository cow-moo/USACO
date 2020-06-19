#include <iostream>
using namespace std;

int r[2010];
int main(){
    int n,ans=2000000000,dist;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int i=n;i<2*n;i++){
        r[i]=r[i-n];
    }
    for(int i=0;i<n;i++){
        dist=0;
        for(int j=i;j<i+n;j++){
            dist+=(j-i)*r[j];
        }
        if(dist<ans){
            ans=dist;
        }
    }
    cout<<ans;
}
