#include <iostream>
using namespace std;

int h[500];
int main(){
    int n,q,sum,s,e;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<q;i++){
        sum=0;
        cin>>s>>e;
        for(int i=s-1;i<e;i++){
            sum+=h[i];
        }
        cout<<sum<<endl;
    }

}
