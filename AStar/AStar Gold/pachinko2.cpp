#include <iostream>
using namespace std;

int r[105][105];

int main(){
    int rows;
    cin>>rows;
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++)
            cin>>r[i][j];//rownum,colnum
    }
    for(int i=rows-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            r[i][j]=r[i][j]+max(r[i+1][j],r[i+1][j+1]);
        }
    }
    cout<<r[0][0]<<endl;
}
