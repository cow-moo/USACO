#include <iostream>
using namespace std;

int main(){
    char c;
    int n,counter=0;
    string input;
    cin>>c>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        for(int j=0;j<input.length();j++){
            if(input[j]==c)
                counter++;
        }
    }
    cout<<counter;
}
