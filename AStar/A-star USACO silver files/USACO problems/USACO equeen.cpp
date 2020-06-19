#include <iostream>
#include <cmath>
using namespace std;

int queensi[1000];
int solutioncount=0,n;

void recurse(int row){
    int tempqueens[10];
    for(int i=0;i<row;i++){
        tempqueens[i]=queensi[i];
    }
    if(row==n){
        solutioncount++;
    }
    bool works;
    for(int i=0;i<n;i++){
        works=true;
        for(int j=0;j<row;j++){
            if(queensi[j]==i || ((row-j)==abs(queensi[j]-i))){
                works=false;
            }
        }
        if(works){
            queensi[row]=i;
            recurse(row+1);
            for(int i=0;i<row;i++){
                queensi[i]=tempqueens[i];
            }
        }
    }
}

int main(){
    cin>>n;
    recurse(0);
    cout<<solutioncount<<endl;
}
