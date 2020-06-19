#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int snakes[405];
set<int> dividers;

int main(){
    freopen("snakes.in","r",stdin);
    //freopen("snakes.out","w",stdout);
    int n,k,maxim=0,prev,cur,minim,maxindex,maxrange,ans=0,stop;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>snakes[i];
        if(snakes[i]>maxim)
            maxim=snakes[i];
    }
    for(int i=0;i<n;i++)
        snakes[i]=maxim-snakes[i];
    dividers.insert(n);
    for(int i=0;i<k;i++){
        maxim=-1;
        prev=0;
        for(set<int>::iterator it=dividers.begin();it!=dividers.end();++it){
            cur=*it;
            minim=1000000;
            for(int j=prev;j<cur;j++){
                if(snakes[j]==0)
                    break;
                if(snakes[j]<minim)
                    minim=snakes[j];
                if((j-prev+1)*minim>maxim){
                    maxim=(j-prev+1)*minim;
                    maxindex=j+1;
                    maxrange=prev;
                }
            }
            minim=1000000;
            for(int j=cur-1;j>=prev;j--){
                if(snakes[j]==0)
                    break;
                if(snakes[j]<minim)
                    minim=snakes[j];
                if((cur-j)*minim>maxim){
                    maxim=(cur-j)*minim;
                    maxindex=j;
                    maxrange=cur;
                }
            }
            prev=cur;
        }
        if(maxim==-1)
            continue;
        if(maxindex>maxrange){
            for(int j=maxrange;j<maxindex;j++)
                snakes[j]-=maxim/(maxindex-maxrange);
        }
        else{
            for(int j=maxrange-1;j>=maxindex;j--)
                snakes[j]-=maxim/(maxrange-maxindex);
        }
        dividers.insert(maxindex);
    }
    for(set<int>::iterator it=dividers.begin();it!=dividers.end();++it)
        cout<<*it<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<snakes[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        ans+=snakes[i];
    cout<<ans<<endl;
}
