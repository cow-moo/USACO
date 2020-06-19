#include <iostream>
using namespace std;

int main(){
    int n,row=0,counter=0;
    cin>>n;
    while(row<n){
        if(counter<=row){
            cout<<"*";
            counter++;
        }
        if(counter==row+1){
            cout<<endl;
            counter=0;
            row++;
        }
    }
}
