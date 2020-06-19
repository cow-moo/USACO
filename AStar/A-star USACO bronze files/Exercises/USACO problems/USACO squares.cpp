#include <iostream>
using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    for(int i=1;(i*i)<n;i++){
        if(n%i==0){
            if((i+n/i)%2==0){
                ans++;
            }
        }
    }
    cout<<ans;
}
