#include <iostream>
using namespace std;

int main(){
    string num;
    cin>>num;
    for(int i=0;i<num.length();i++){
        (num[i]=='0') ? num[i]='1' : num[i]='0';
        cout<<num<<endl;
        (num[i]=='0') ? num[i]='1' : num[i]='0';
    }
}
