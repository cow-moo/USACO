#include <iostream>
#include <algorithm>
using namespace std;

int diamonds[1000];
int main(){
    int n,k,ans=0,sum=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>diamonds[i];
    }
    sort(diamonds,diamonds+n);
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            if(diamonds[i]+k>=diamonds[j])
                sum++;
            else
                break;
        }
        if(sum>ans)
            ans=sum;
    }
    cout<<ans;
}
