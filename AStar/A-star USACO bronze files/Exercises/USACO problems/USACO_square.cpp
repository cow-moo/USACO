#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    int x,y,minx=10,maxx=0,miny=10,maxy=0;
    for(int i=0;i<4;i++){
        cin>>x>>y;
        if(x<minx)
            minx=x;
        if(x>maxx)
            maxx=x;
        if(y<miny)
            miny=y;
        if(y>maxy)
            maxy=y;
    }
    cout<<max(maxx-minx,maxy-miny)*max(maxx-minx,maxy-miny);
}
