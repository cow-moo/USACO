#include <iostream>
using namespace std;

char figurine[20][20];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>figurine[i][j];
        }
    }
}
