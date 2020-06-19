#include <iostream>
using namespace std;

int main(){
    int a,b,e,output=0;
    long long x;
    cin>>a>>b;
    for(e=a+1;e<=62;e++){
        x = 1LL<<e;
        do
        {
            x/=10;
        }while(x>9);
        if(x==b){
            output = e;
            break;
        }
    }
    cout<<output<<endl;
}

