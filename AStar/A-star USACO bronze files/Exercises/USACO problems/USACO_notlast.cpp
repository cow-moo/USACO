#include <iostream>
#include <stdio.h>
using namespace std;
string names[8] = {"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};
int cowmilk[8];

int main(){
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    int n,temp2,min1=999999,min2=999999;
    string temp1;
    bool tie = false;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp1;
        cin>>temp2;
        for(int j=0;j<7;j++){
            if(temp1==names[j])
                cowmilk[j]+=temp2;
        }
    }
    for(int i=0;i<7;i++){
        //cout<<cowmilk[i]<<endl;
        min1 = min(cowmilk[i],min1);
    }
    for(int i=0;i<7;i++){
        if(cowmilk[i]==min2){
            tie = true;
        }
        else if(cowmilk[i]!=min1){
            min2 = min(cowmilk[i],min2);
        }
    }
    if(min2==999999)
        tie=true;
    if(tie)
        cout<<"Tie"<<endl;
    else{
        for(int i=0;i<7;i++){
            if(cowmilk[i]==min2)
                cout<<names[i]<<endl;
        }
    }
}
