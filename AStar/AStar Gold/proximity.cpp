#include <iostream>
using namespace std;

int line[50005],ids[1000005];

int main(){
    int n,k,maxim=-1;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>line[i];
    for(int i=0;i<n;i++){
        if(ids[line[i]]>0 && line[i]>maxim)
            maxim=line[i];
        if(i-k>=0)
            ids[line[i-k]]--;
        ids[line[i]]++;
    }
    cout<<maxim<<endl;
}
