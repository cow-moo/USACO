#include <iostream>
using namespace std;

int main(){
    int n,row=0,counter=0;
    cin>>n;
    while(row<((n%2==0)?n/2:n/2+1)){
        if(counter<=row){
            cout<<"*";
            counter++;
        }
        if(counter==row+1){
            cout<<endl;
            counter = 0;
            row++;
        }
    }
    row=0;
    counter=0;

    n/=2;
    while(row<=n){
        if(counter<(n-row)){
            cout<<"*";
            counter++;
        }
        else{
            cout<<endl;
            counter=0;
            row++;
        }
    }
}
