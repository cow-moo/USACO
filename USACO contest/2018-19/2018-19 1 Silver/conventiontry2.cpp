#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int times[100005];
int dividers[100005];
int wait[100005];
int n,m,c;

int maxwait(){
    int maxtime=0;
    for(int i=0;i<m;i++){
        if(times[dividers[i+1]-1]-times[dividers[i]]>maxtime)
            maxtime=times[dividers[i+1]-1]-times[dividers[i]];
        wait[i]=times[dividers[i+1]-1]-times[dividers[i]];
    }
    return maxtime;
}

int main(){
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    int minwait,maxim;
    cin>>n>>m>>c;
    for(int i=0;i<n;i++)
        cin>>times[i];
    sort(times,times+n);
    for(int i=1;i<m;i++){
        if(i<=(n-m)/(c-1))
            dividers[i]=c*i;
        else if(i==(n-m)/(c-1)+1)
            dividers[i]=dividers[i-1]+(n-m)%(c-1)+1;
        else
            dividers[i]=dividers[i-1]+1;
    }
    dividers[0]=0;
    dividers[m]=n;
    /*for(int i=0;i<n;i++)
        cout<<times[i]<<" ";
    cout<<endl;
    for(int i=0;i<=m;i++)
        cout<<dividers[i]<<" ";
    cout<<endl;
    cout<<maxwait()<<endl;*/
    minwait=maxwait();
    /*for(int i=0;i<m;i++)
        cout<<wait[i]<<" ";
    cout<<endl;*/
    bool stop=false;
    while(!stop){
        //temp=maxwait();
        //if(temp<minwait)
        //    minwait=temp;
        for(int i=m-1;i>0;i--){
            if(dividers[i+1]-dividers[i]<c && dividers[i]-dividers[i-1]>1){
                dividers[i]--;//moving i changes wait[i-1] and wait[i]

                wait[i-1]=times[dividers[i]-1]-times[dividers[i-1]];
                wait[i]=times[dividers[i+1]-1]-times[dividers[i]];
                maxim=0;
                for(int j=0;j<m;j++){
                    if(wait[j]>maxim)
                        maxim=wait[j];
                }
                //cout<<maxim<<endl;
                if(maxim<minwait)
                    minwait=maxim;
                break;
            }
            if(i==2)
                stop=true;
        }
    }
    cout<<minwait<<endl;
}

