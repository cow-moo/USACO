#include <iostream>
using namespace std;

int rlength[105],rspeed[105];
int main(){
    int n,m,dist=0,blength,bspeed,speedover=0,counter,sum,lowindex,highindex;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>rlength[i]>>rspeed[i];
    for(int i=0;i<m;i++){
        cin>>blength>>bspeed;
        lowindex=100000;
        highindex=0;
        sum=0;
        for(int j=0;;j++){
            if(dist>=sum)
                lowindex=j;
            if(rlength[j]+sum>=blength+dist){
                highindex=j;
                break;
            }
            sum+=rlength[j];
        }
        for(int j=lowindex;j<=highindex;j++){
            if(bspeed-rspeed[j]>speedover){
                speedover=bspeed-rspeed[j];
            }
        }
        dist+=blength;
    }
    cout<<speedover;
}
