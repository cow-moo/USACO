#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int scores[100050],n,maxave[2],mink[100000],kindex=0;

int findmin(int i){
    int mins=10001;
    for(i;i<n;i++){
        if(scores[i]<mins)
            mins=scores[i];
    }
    return mins;
}

int findminindex(int i){
    int mins=10001,mini;
    for(i;i<n;i++){
        if(scores[i]<=mins){
            mins=scores[i];
            mini=i;
        }
    }
    return mini;
}

/*void resetk(){
    for(int i=0;i<=100000;i++){
        if(mink[i]==-1)
            break;
        else
            mink[i]=-1;
    }
}*/

int main(){
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    int minscore,minindex,sum=0,curnums;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>scores[i];
        sum+=scores[i];
    }
    minindex = findminindex(0);
    minscore = findmin(0);
    sum-=minscore;
    curnums=n-1;
    maxave[0] = -1;
    maxave[1] = 1;
    //resetk();
    for(int k=0;k<n-2;k++){
        if(k==minindex){
            minindex = findminindex(k+1);
            minscore = findmin(k+1);
            /*
            cout<<endl;
            cout<<"k: "<<k+1<<endl;
            cout<<"minindex: "<<minindex<<endl;
            cout<<"minscore: "<<minscore<<endl;
            cout<<endl;
            */
            sum-=minscore;
        }
        else{
            sum-=scores[k];
        }
        curnums--;
        if(sum*maxave[1] > curnums * maxave[0]){
            maxave[0] = sum;
            maxave[1] = curnums;
            mink[0] = k;
            kindex = 1;
        }
        else if(sum*maxave[1] == curnums * maxave[0] && mink[kindex]!=k){
            mink[kindex++] = k;
        }
        else{

        }
        //cout<<k+1<<": "<<sum<<"/"<<curnums<<endl;
    }
    //cout<<endl<<endl;
    //cout<<maxave[0]<<"/"<<maxave[1]<<endl;
    //sort(mink,mink+kindex);
    for(int i=0;i<kindex;i++)
        cout<<mink[i]+1<<endl;
}
