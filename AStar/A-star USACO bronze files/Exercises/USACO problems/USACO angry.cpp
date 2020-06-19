#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int x[110];
int main(){
    int n,counter,ans=0,minx,maxx,t;
    bool explode,low,high;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    for(int i=0;i<n;i++){
        t=1;
        minx=x[i]-t;
        maxx=x[i]+t;
        low=false;
        high=false;
        explode = true;
        while(explode){
            t++;
            explode = false;
            if(!low){
                for(int j=0;j<i;j++){
                    if(minx-1==x[j]-t){
                        low=true;
                        break;
                    }
                    if(x[j]>=minx && x[j]<=maxx){
                        minx=x[j]-t;
                        explode = true;
                        break;
                    }
                }
            }
            if(!high){
                for(int j=n-1;j>i;j--){
                    if(maxx+1==x[j]+t){
                        high=true;
                        break;
                    }
                    if(x[j]>=minx && x[j]<=maxx){
                        maxx=x[j]+t;
                        explode = true;
                        break;
                    }
                }
            }
        }
        counter=0;
        for(int j=0;j<n;j++){
            if(x[j]>=minx && x[j]<=maxx)
                counter++;
        }
        if(counter>ans)
            ans=counter;
    }
    cout<<ans;
}
