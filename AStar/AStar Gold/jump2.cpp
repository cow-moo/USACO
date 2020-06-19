#include <iostream>
#include <algorithm>
using namespace std;

int rocks[50005];

int main(){
    int l,n,m,mcount,jsize;
    cin>>l>>n>>m;
    jsize=l/2;
    for(int i=1;i<=n;i++)
        cin>>rocks[i];
    rocks[0]=0;
    rocks[n+1]=l;
    sort(rocks,rocks+n+2);
    /*for(int i=0;i<=n+1;i++)
        cout<<rocks[i]<<endl;*/
    while(1){//binary search
        mcount=0;
        for(int i=0;i<n;i++){
            for(int j=1;i+j<=n+1;j++){
                if((rocks[i+j]-rocks[i])>jsize){
                    mcount+=j-1;
                    i+=j-1;
                    break;
                }
            }
        }
        if(mcount==m){
            cout<<jsize<<endl;
            break;
        }
        else if(mcount>m){
            jsize=jsize/2;
        }
        else{
            jsize=(jsize+l)/2;
        }
    }
}
