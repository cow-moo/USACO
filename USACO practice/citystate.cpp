#include <iostream>
#include <stdio.h>
using namespace std;

string citystate[200005][2];

int main(){
    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);
    int n,counter=0;
    string input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        citystate[i][0]+=input[0];
        citystate[i][0]+=input[1];
        cin>>input;
        citystate[i][1]=input;
    }
    /*for(int i=0;i<n;i++){
        cout<<citystate[i][0]<<" "<<citystate[i][1]<<endl;
    }*/
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(citystate[i][0]==citystate[j][1] && citystate[j][0]==citystate[i][1])
                counter++;
        }
    }
    cout<<counter<<endl;
}
