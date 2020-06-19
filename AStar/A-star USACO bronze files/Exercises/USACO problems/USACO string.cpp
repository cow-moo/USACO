#include <iostream>
using namespace std;

int main(){
    int z,n,c;
    string str;
    cin>>z;
    for(int i=0;i<z;i++){
        cin>>n>>c;
        cin>>str;
        for(int j=0;j<c;j++){
            str=str.substr(n)+str;
        }
        cout<<str<<endl;
    }
}
