#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    freopen("cowsignal.in","r",stdin);
    freopen("cowsignal.out","w",stdout);
    int m,n,k;
    string signal;
    cin>>m>>n>>k;
    for(int i=0;i<m;i++){
        cin>>signal;
        for(int h=0;h<k;h++){
            for(int j=0;j<n;j++){
                for(int l=0;l<k;l++)
                    cout<<signal[j];
            }
            cout<<endl;
        }
    }
}
