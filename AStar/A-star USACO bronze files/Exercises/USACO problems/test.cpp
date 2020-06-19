#include <iostream>
#include <stdio.h>
using namespace std;

int shuffle[100050],path[100050];

bool loop(int cownum){
    //cout<<cownum<<endl;
    int pathi=1;
    path[0]=cownum;
    bool cont=true;
    while(cont){
        path[pathi++]=shuffle[cownum];
        cownum=shuffle[cownum];
        //cout<<cownum<<" ";
        for(int i=0;i<pathi;i++){
            if(shuffle[cownum]==path[i]){
                cont=false;
                //cout<<i<<" "<<path[i];
                break;
            }
        }
    }
    //cout<<endl;
    /*
    for(int i=0;i<pathi;i++){
        cout<<path[i]<<" ";
    }*/
    //cout<<endl<<endl;
    if(shuffle[cownum]==path[0])
        return true;
    else
        return false;
}

int main(){
    freopen("shuffle.in","r",stdin);
    //freopen("shuffle.out","w",stdout);
    int n,counter=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>shuffle[i];
        shuffle[i]--;
    }
    for(int i=0;i<n;i++){
        if(loop(i)){
            counter++;
            //cout<<i<<endl;
        }
    }
    cout<<counter<<endl;
}
