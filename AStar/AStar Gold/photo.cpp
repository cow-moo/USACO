#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n,photo[20000];
map<int,int> photographs[5];


bool appears3(int index1,int index2){
    int appearnum=0;
    for(int i=0;i<5;i++){
        if(photographs[i][index2]>photographs[i][index1])
            appearnum++;
        if(appearnum>=3)
            return true;
    }
    return false;
}

int main(){
    int temp;
    cin>>n;
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            photo[j]=temp;
            photographs[i][temp]=j;
        }
    }
    sort(photo,photo+n,appears3);
    for(int i=0;i<n;i++){
        cout<<photo[i]<<endl;
    }
}
