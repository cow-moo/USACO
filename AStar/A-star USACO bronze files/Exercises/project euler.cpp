#include <iostream>
using namespace std;

int main(){
    int ans=0,length=0,num;
    for(int i=1;i<1000000;i++){
        num=i;
        for(int j=0;;j++){
            if(num%2==0)
                num/=2;
            else
                num=num*3 + 1;
            if(num==1){
                length=i;
                break;
            }
        }
        if(length>ans)
            ans=length;
        cout<<i<<endl;
    }
    cout<<ans;
}
