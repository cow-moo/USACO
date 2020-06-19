#include <iostream>
#include <stdio.h>
using namespace std;

int cowids[100050];  //cowids[0] is nobody
int milk[1000050];   //milk[0] is nobody
int n;               //log[i][0] = 0 means no cow
int log[1000050][2]; //log[i][0] is which cow,log[i][1] is change,day 1 is index 1
bool oldhigh[1000050],newhigh[1000050];

int maximum(){
    int maxmilk=0;
    for(int i=1;i<=n;i++){
        maxmilk=max(maxmilk,milk[i]);
    }
    return maxmilk;
}

int main(){
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    int g,input,input2,cowcount=1,maxdays=0,changes=0;
    bool newcow;
    cin>>n>>g;
    for(int i=0;i<n;i++){
        cin>>input>>input2;
        cin>>log[input][1];
        newcow = true;
        for(int j=1;j<cowcount;j++){
            if(cowids[j]==input2){
                log[input][0]=j;
                newcow = false;
                break;
            }
        }
        if(newcow){
            cowids[cowcount]=input2;
            log[input][0]=cowcount;
            cowcount++;
        }
        maxdays = max(maxdays,input);
    }
    //cout<<maxdays<<endl;
    for(int i=1;i<=maxdays;i++){
        //cout<<endl<<i<<":"<<log[i][0]<<endl;
        if(log[i][0]!=0){
            //cout<<log[i][1]<<" ";
            milk[log[i][0]]+=log[i][1];
            for(int j=1;j<cowcount;j++){
                if(milk[j]==maximum()){
                    newhigh[j-1]=true;
                }
                else{
                    newhigh[j-1]=false;
                }
            }
            for(int j=0;j<cowcount-1;j++){
                if(oldhigh[j]!=newhigh[j]){
                    changes++;
                    break;
                }
            }
            for(int j=0;j<cowcount-1;j++)
                oldhigh[j]=newhigh[j];
        }
    }
    //cout<<endl<<cowcount<<endl;
    /*for(int i=1;i<cowcount;i++){
        cout<<cowids[i]<<":"<<milk[i]<<endl;
    }*/
    cout<<changes<<endl;
/*
    for(int i=1;i<101;i++){
        if(log[i][0]!=0){
            milk[log[i][0]]+=log[i][1];
            for(int j=1;j<=3;j++){
                if(milk[j]==max(max(milk[1],milk[2]),milk[3]))
                    newhigh[j-1]=true;
                else
                    newhigh[j-1]=false;
            }
            for(int j=0;j<3;j++){
                if(oldhigh[j]!=newhigh[j]){
                    changes++;
                    break;
                }
            }
            for(int j=0;j<3;j++){
                oldhigh[j]=newhigh[j];
            }
        }
    }
    cout<<changes<<endl;*/
}
