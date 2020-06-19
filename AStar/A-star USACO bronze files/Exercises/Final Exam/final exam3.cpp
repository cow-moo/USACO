#include <iostream>
using namespace std;

int main(){
    int n,input,counter=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        if(input==7)
            counter++;
    }
    cout<<counter;
}
