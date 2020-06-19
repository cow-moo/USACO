#include <iostream>
using namespace std;

int main(){
    int n,row=0,counter=0;
    cin>>n;
    while(row<n){
        if(counter<(n-row-1)){
            cout<<" ";
            counter++;
        }
        else if(counter<=(n+row-1)){
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

