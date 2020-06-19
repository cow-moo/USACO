#include <iostream>
#include <stdio.h>
using namespace std;

string oldorder[105];
string neworder[105];
int shuffle[105];

int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>shuffle[i];
        shuffle[i]--;
    }
    for(int i=0;i<n;i++){
        cin>>oldorder[i];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            neworder[j]=oldorder[shuffle[j]];
        }
        for(int j=0;j<n;j++){
            oldorder[j]=neworder[j];
        }
    }
    for(int i=0;i<n;i++)
        cout<<neworder[i]<<endl;
}
