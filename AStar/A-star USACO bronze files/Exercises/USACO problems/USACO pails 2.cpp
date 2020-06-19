#include <iostream>
using namespace std;
int arrtimes[10000];
int main(){
    int n,arr[10000],m,total;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>m;
    total = 0;
    /*while(arrtimes[n-1]<(m/arr[n-1]+1)){
        if ((xtimes*x+ytimes*y)>total){
            total=xtimes*x+ytimes*y;
        }
        if(xtimes*x<=m){
            xtimes++;
        }
        if((xtimes*x+ytimes*y)>m){
            ytimes++;
            xtimes=0;
        }
    }*/
    cout<<total<<endl;
}
