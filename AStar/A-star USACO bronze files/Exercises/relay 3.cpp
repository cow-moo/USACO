#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    char addition;
    string num,ans;
    int carryover=0;
    cin>>num;
    for(int i=num.length()-1;i>=0;i--){
        addition=2*(num[i]-'0')+carryover+'0';
        if(2*(num[i]-'0')+carryover>=10){
            carryover=1;
        }
        else{
            carryover=0;
        }
        addition-=carryover*10;
        ans = addition+ans;
    }
    if(carryover==1){
        ans='1'+ans;
    }
    cout<<ans<<endl;
}
