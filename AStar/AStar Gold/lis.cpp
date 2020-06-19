#include <iostream>
using namespace std;

int sequence[20005],subcount[20005];

int main(){
    int n,maxim=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sequence[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(subcount[j]+1>subcount[i] && sequence[j]<sequence[i])
                subcount[i]=subcount[j]+1;
        }
        if(subcount[i]>maxim)
            maxim=subcount[i];
    }
    cout<<maxim+1<<endl;
}
