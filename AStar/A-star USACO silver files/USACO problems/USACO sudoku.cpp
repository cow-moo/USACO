#include <iostream>
using namespace std;

short sudoku[10][10];
bool ansfound=false;

void recurse(int n,int row){
    if(ansfound)
        return;
    for(int i=0;i<9;i++){
        if(n==sudoku[row][i]){
            if(n==9){
                if(row==8){
                    ansfound=true;
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        cout<<sudoku[i][j]<<" ";
                    }
                    cout<<endl;
                }
                    return;
                }
                else
                    recurse(1,row+1);
            }
            else
                recurse(n+1,row);
            return;
        }
    }
    int temp[10];
    for(int i=0;i<9;i++){
        temp[i]=sudoku[row][i];
    }
    for(int i=0;i<9;i++){
        if(sudoku[row][i]!=0)
            continue;
        bool temporary=true;
        for(int j=0;j<9;j++){
            if(sudoku[j][i]==n){
                temporary=false;
                break;
            }
        }
        for(int j=0;j<=2;j++){
            for(int k=0;k<=2;k++){
                if(sudoku[row/3*3+j][i/3*3+k]==n){
                    temporary=false;
                    break;
                }
            }
        }
        if(!temporary)
            continue;
        sudoku[row][i]=n;
        if(n==9){
            if(row==8){
                ansfound=true;
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        cout<<sudoku[i][j]<<" ";
                    }
                    cout<<endl;
                }
                return;
            }
            else{
                recurse(1,row+1);
                for(int j=0;j<9;j++){
                    sudoku[row][j]=temp[j];
                }
            }
        }
        else{
            recurse(n+1,row);
            for(int j=0;j<9;j++){
                sudoku[row][j]=temp[j];
            }
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    recurse(1,0);
    if(!ansfound)
        cout<<"NO SOLUTION"<<endl;
}
