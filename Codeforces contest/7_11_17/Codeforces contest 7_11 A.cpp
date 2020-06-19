#include <iostream>
#include <math.h>
using namespace std;

int arr[200000];
int main(){
    int n,a,b,ans=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            if(a>0)
                a--;
            else if(b>0){
                b--;
                a++;
            }
            else
                ans++;
        }
        else{
            if(b>0)
                b--;
            else
                ans+=2;
        }
    }
    cout<<ans<<endl;
}
