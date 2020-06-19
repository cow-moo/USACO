#include <iostream>
#include <stdio.h>
using namespace std;

int d[10005],curcow[10005];

int main(){
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    int n,tmax,t=0,cown=0,j,maxim=0,minim=1000000,sum=0;
    bool done=false,quit=false;
    cin>>n>>tmax;
    for(int i=0;i<n;i++){
        cin>>d[i];
        sum+=d[i];
    }
    for(int k=sum/tmax-1;k<=n;k++){
        //cout<<endl<<"k:"<<k<<endl;
        t=0;
        for(cown=0;cown<k;cown++){
            curcow[cown]=d[cown];
        }
        quit=false;
        while(1){
            //
            minim=1000000;
            for(int j=0;j<k;j++){
                if(curcow[j]<minim)
                    minim=curcow[j];
            }
            t+=minim;
            if(t>tmax)
                break;
            for(int j=0;j<k;j++){
                curcow[j]-=minim;
                if(curcow[j]==0)
                    curcow[j]=d[cown++];
                //cout<<curcow[j]<<" ";
            }
            //cout<<"t:"<<t<<endl;
            if(cown==n+1){
                //cout<<"spaghetti"<<endl;
                maxim=0;
                for(int l=0;l<k;l++){
                    if(curcow[l]>maxim)
                        maxim=curcow[l];
                }
                if(maxim+t<=tmax)
                    done=true;
                else{
                    quit=true;
                }
                if(done){
                    cout<<k<<endl;
                    break;
                }
            }
            if(done || quit)
                break;
            //
            /*for(j=0;j<k;j++){
                curcow[j]--;
                if(curcow[j]==0)
                    curcow[j]=d[cown++];
                if(cown==n+1){
                    for(int l=0;l<k;l++){
                        if(curcow[l]>maxim)
                            maxim=curcow[l];
                    }
                    if(maxim+t<=tmax)
                        done=true;
                    else{
                        quit=true;
                    }
                    if(done){
                        cout<<k<<endl;
                        break;
                    }
                }
                //cout<<curcow[j]<<" ";
            }
            if(++t>tmax || done || quit)
                break;*/
            //cout<<"t:"<<t<<endl;
        }
        if(done)
            break;
    }
}
