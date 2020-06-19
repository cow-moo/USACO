#include <iostream>
using namespace std;

int arr[1001];
int factors[1001];
int main(){
    int n,counter=0;
    cin>>n;
    for(int i=2;i<n;i++){
        if(n%i==0){
            factors[counter]=i;
            counter++;
        }
    }
    for(int i=0;i<counter;i++){
        for(int j=factors[i];j<=n;j+=factors[i]){
            arr[j]=1;
        }
    }
    for(int i=1;i<n;i++){
        if(arr[i]==0)
            cout<<i;
    }
}
