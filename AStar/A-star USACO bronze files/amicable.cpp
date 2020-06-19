#include <iostream>
using namespace std;

int divsum[10001];
int main(){
    int sum=0;
    for(int i=1;i<=10000;i++){
        sum=0;
        for(int j=1;j<i;j++){
            if(i%j==0){
                sum+=j;
            }
        }
        divsum[i]=sum;
    }
    for(int i=1;i<=10000;i++){
        for(int j=i+1;j<=10000;j++){
            if(divsum[i]==j && divsum[j]==i){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}
