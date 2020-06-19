#include <iostream>
using namespace std;

int tri[25][25];
int main(){
    int n,s;
    cin>>n>>s;
    for(int j=0;j<n;j++){
        for(int i=0;i<=j;i++){
            tri[i][j]=(s-1)%9 + 1;
            s++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tri[i][j]==0)
                cout<<" ";
            else
                cout<<tri[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}
