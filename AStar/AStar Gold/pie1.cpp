#include <iostream>
using namespace std;

int field[105][105];

int main(){
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>field[i][j];
        }
    }
    for(int i=1;i<r;i++){
        for(int j=0;j<r-i;j++){
            field[r-i][j]=-1;
        }
    }
    for(int j=1;j<c;j++){
        for(int i=0;i<r;i++){
            if(i==0){
                field[i][j]+=max(field[i][j-1],field[i+1][j-1]);
            }
            else if(i==r-1){
                field[i][j]+=max(field[i][j-1],field[i-1][j-1]);
            }
            else{
                field[i][j]+=max(field[i-1][j-1],max(field[i][j-1],field[i+1][j-1]));
            }
        }
    }
    cout<<field[r-1][c-1]<<endl;
}
