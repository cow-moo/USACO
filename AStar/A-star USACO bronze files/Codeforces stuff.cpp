#include <iostream>
using namespace std;

int main(){
    string p;
    bool boolean=true;
    cin>>p;
    for(int i=0;i<p.length();i++){
        if(p[i]=='H' || p[i]=='Q' || p[i]=='9' || p[i]=='+'){
            cout<<"YES";
            boolean=false;
            break;
        }
    }
    if(boolean){
        cout<<"NO";
    }
}
