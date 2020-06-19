#include <iostream>
#include <stdlib.h>
using namespace std;

int field[405][405];

int main(){
    int n,k,sum,maxim=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>field[i][j];
    }
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            sum=0;
            for(int i=-k;i<=k;i++){
                for(int j=abs(i)-k;j<=k-abs(i);j++){
                    if(r+i>=0 && r+i<n && c+j>=0 && c+j<n)
                        sum+=field[r+i][c+j];
                }
            }
            if(sum>maxim)
                maxim=sum;
        }
    }
    cout<<maxim<<endl;
}
