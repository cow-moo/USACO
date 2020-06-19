#include <iostream>
#include <stdio.h>
using namespace std;

int t[20005],ab[20005][2];
bool cowused[20005];

int main(){
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int c,n,counter=0;
    cin>>c>>n;
    for(int i=0;i<c;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        cin>>ab[i][0]>>ab[i][1];
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<n;j++){
            if(ab[j][0]<=t[i] && t[i]<=ab[j][1] && !cowused[j]){
                counter++;
                cowused[j]=1;
                break;
            }
        }
    }
    cout<<counter<<endl;
}
