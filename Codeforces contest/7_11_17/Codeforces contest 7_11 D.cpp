#include <iostream>
using namespace std;

int main(){
    int n,k,node = 1,x;
    cin>>n>>k;
    cout<<n-k+1<<endl;
    for(node;node<=n-k+1;node++){
        cout<<node<<" "<<node+1<<endl;
    }
    k-=2;
    x = node-1;
    node++;
    for(node;node>=0;node++){
        if(k<=0)
            break;
        cout<<x<<" "<<node<<endl;
        k--;
    }
}
