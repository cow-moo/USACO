#include <iostream>
using namespace std;

int cowx[50000];
int cowy[50000];
int main(){
    int n,minx=40000,maxx=0,miny=40000,maxy=0,minxcow,maxxcow,minycow,maxycow,ans;
    cin>>n;
    for(int i=0;i<2*n;i++){
        if(i%2==0)
            cin>>cowx[i/2];
        else
            cin>>cowy[i/2];
    }
    for(int i=0;i<n;i++){
        if(cowx[i]<minx){
            minx=cowx[i];
            minxcow = i;
        }
        if(cowx[i]>maxx){
            maxx=cowx[i];
            maxxcow = i;
        }
    }
    for(int i=0;i<n;i++){
        if(cowy[i]<miny){
            miny=cowy[i];
            minycow = i;

        }
        if(cowy[i]>maxy){
            maxy=cowy[i];
            maxycow = i;
        }
    }
    ans = (maxx-minx)*(maxy-miny);
    int xtremecows[4] = {minxcow,maxxcow,minycow,maxycow};

    for(int j=0;j<4;j++){
        minx=40000,maxx=0,miny=40000,maxy=0;
        for(int i=0;i<n;i++){
            if(i!=xtremecows[j]){
                if(cowx[i]<minx)
                    minx=cowx[i];
                if(cowx[i]>maxx)
                    maxx=cowx[i];
            }
        }
        for(int i=0;i<n;i++){
            if(i!=xtremecows[j]){
                if(cowy[i]<miny)
                    miny=cowy[i];
                if(cowy[i]>maxy)
                    maxy=cowy[i];
            }
        }
        if((maxx-minx)*(maxy-miny)<ans)
            ans = (maxx-minx)*(maxy-miny);
    }
    cout<<ans;
}
