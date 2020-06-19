#include <iostream>
#include <stdio.h>
using namespace std;

void bubble(int length,int x[1000],int y[1000]){
    for(int j=length-1;j>=0;j--){
        for(int i=0;i<j;i++){
            if(x[i]>x[i+1]){
                swap(x[i],x[i+1]);
                swap(y[i],y[i+1]);
            }
        }
    }
}
int arrive[105],duration[105];
int main(){
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);
    int n,time=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arrive[i]>>duration[i];
    }
    bubble(n,arrive,duration);
    for(int i=0;i<n;i++){
        if(arrive[i]>time)
            time=arrive[i]+duration[i];
        else{
            time+=duration[i];
        }
    }
    cout<<time;
}
