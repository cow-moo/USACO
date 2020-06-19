#include <iostream>
#include <math.h>
using namespace std;

int x[400],y[400],r[400],ans[400];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i]>>r[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(((y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]))<(r[i]+r[j])*(r[i]+r[j])){
                ans[i]++;
                ans[j]++;
            }
        }
        cout<<ans[i]<<endl;
    }
}
