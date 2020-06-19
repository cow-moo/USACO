#include <iostream>
using namespace std;

int main(){
    long long a,b,b2=0,temp=1;
    cin>>a>>b;
    while(1){
        temp*=10;
        if(temp>b)
            break;
    }
    while(b>0){
        temp/=10;
        b2+=(b%10)*temp;
        b/=10;
    }
    cout<<a+b2<<endl;
}
