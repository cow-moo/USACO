#include <iostream>

using namespace std;
int main(){
    int x,y,m,total=0,xtimes=0,ytimes=0;
    cin>>x>>y>>m;
    while(ytimes<(m/y+1)){
        xtimes = (m-(y*ytimes))/x;
        if((xtimes*x+ytimes*y)>total)
            total = xtimes*x+ytimes*y;
        ytimes++;
    }
    cout<<total<<endl;
}
