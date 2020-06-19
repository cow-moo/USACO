#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int l,n,rf,rb,extra,taste,curx=0;
int stops[100005][2];

int maximum(){
    int temp=0,index=-1;
    for(int i=0;i<n;i++){
        if(stops[i][1]>=temp && stops[i][0]>curx){
            temp=stops[i][1];
            index=i;
        }
    }
    return index;
}

int main(){
    freopen("reststops.in","r",stdin);
    freopen("reststops.out","w",stdout);
    cin>>l>>n>>rf>>rb;
    extra = l * (rf-rb);
    for(int i=0;i<n;i++){
        cin>>stops[i][0]>>stops[i][1];
    }
    int tempmax;
    while(1){
        tempmax=maximum();
        if(tempmax==-1)
            break;
        //      distance to travel       speed  tastiness
        taste+=(stops[tempmax][0]-curx)*(rf-rb)*stops[tempmax][1];
        curx=stops[tempmax][0];
    }
    cout<<taste<<endl;
}
