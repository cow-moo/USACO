#include <iostream>
#include <stdio.h>
using namespace std;

int fj[100005],n,maxim=0;
char choices[3] = {'H','P','S'};

bool beat(int a,int b){
    if(a-b==1 || a-b==-2)
        return true;
    else
        return false;
}

void hps(int choice1,int choice2){
    int wins=0;
    for(int i=0;i<n;i++){
        if(beat(choice2,fj[i]))
            wins++;

    }
    for(int i=0;i<n;i++){
        if(beat(choice1,fj[i]))
            wins++;
        if(beat(choice2,fj[i]))
            wins--;
        if(wins>maxim){
            maxim=wins;
        }
    }
}

int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    char temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp=='H')
            fj[i]=0;
        else if(temp=='P')
            fj[i]=1;
        else
            fj[i]=2;
    }
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i==j)
                continue;
            hps(i,j);
        }
    }
    cout<<maxim<<endl;
}
