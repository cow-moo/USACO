#include <iostream>
using namespace std;

int main(){
    int k,g,n,dist=0;
    int d,v;
    bool temp=false;
    cin>>k>>g>>n;
    for(int i=0;i<n;i++){
        cin>>d>>v;
        if((dist+g)<d){
            cout<<-1<<endl<<dist+g<<endl;
            temp=true;
            break;
        }
        else{
            g-=(d-dist);
            g+=v;
            dist=d;
        }
    }
    if((dist+g)>k){
        cout<<1<<endl<<dist+g-k<<endl;
    }
    else{
        if(!temp)
            cout<<-1<<endl<<k-g<<endl;
    }
}
