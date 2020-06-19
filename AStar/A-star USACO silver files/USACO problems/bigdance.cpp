#include <iostream>
using namespace std;

int sum,n;

void recurse(int start,int stop){
    if(stop-start==1){
        sum+=stop*start;
    }
    else if(stop-start>1){
        recurse(start,start+(stop-start)/2);
        recurse(start+(stop-start)/2+1,stop);
    }
}

int main(){
    cin>>n;
    recurse(1,n);
    cout<<sum<<endl;
}
