#include <iostream>
using namespace std;

int main(){
    int n,row=1,counter=0;
    cin>>n;
    while(row<=n){
        if(counter<(n-row)){
            cout<<" ";
            counter++;
        }
        else{
            cout<<"*";
            counter++;
        }
        if(counter==n){
            cout<<endl;
            counter=0;
            row++;
        }

    }
}
