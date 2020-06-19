#include <iostream>
using namespace std;

int digitsum(int x){
    int sum=0;
    while(1){
        if(x>0){
            sum+=x%10;
            x/=10;
        }
        else
            break;
    }
    return sum;
}

int main(){
    int k,kcount=0;
    cin>>k;
    for(int i=19;;i+=9){
        if(digitsum(i)==10)
            kcount++;
        if(kcount==k){
            cout<<i<<endl;
            break;
        }
    }
}
