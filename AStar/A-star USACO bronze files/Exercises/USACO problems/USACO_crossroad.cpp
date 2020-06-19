#include <iostream>
#include <stdio.h>
using namespace std;

int cows[10]={2,2,2,2,2,2,2,2,2,2};
int main(){
    freopen("crossroad.in","r",stdin);
    freopen("crossroad.out","w",stdout);
    int n,cowin,locin,crosses=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cowin>>locin;
        if(cows[cowin-1]==2)
            cows[cowin-1]=locin;
        if(cows[cowin-1]!=locin){
            crosses++;
            cows[cowin-1]=1-cows[cowin-1];
        }
    }
    cout<<crosses;
}
