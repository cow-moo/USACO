#include <iostream>
#include <stdio.h>
using namespace std;

int milk[4] = {0,7,7,7};
int log[105][2]; //log[i][0] is which cow,log[i][1] is change,day 1 is index 1
bool oldhigh[3]={1,1,1},newhigh[3];
string names[4] = {"NaN","Bessie","Elsie","Mildred"};

int main(){
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    int n,inp,changes=0;
    string input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp>>input;
        for(int j=1;j<4;j++){
            if(input[0]==names[j][0]){
                log[inp][0]=j;
                cin>>log[inp][1];
            }
        }
    }
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
    cout<<changes<<endl;
}
