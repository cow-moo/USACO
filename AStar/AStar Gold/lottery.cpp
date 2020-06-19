#include <iostream>
using namespace std;

int bills[5]={100,20,10,5,1};

int main(){
    int n,bcount=0;
    cin>>n;
    for(int i=0;i<5;i++){
        while(1){
            if(n>=bills[i]){
                n-=bills[i];
                bcount++;
            }
            else
                break;
        }
    }
    cout<<bcount<<endl;
}
