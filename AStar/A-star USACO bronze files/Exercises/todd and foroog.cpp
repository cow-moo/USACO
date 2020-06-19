#include <iostream>
#include <string>
using namespace std;

int moves[1000],board[10000];//,moves2[1000];
string torf[4] = {"","T","F","-"};
int main(){
    int movecount=0,n,input,boolean;
    cout<<"Enter board size n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        if(i<n/2)
            board[i]=1;
        else if(i>n/2)
            board[i]=2;
        else
            board[i]=3;
    }
    while(1){
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<"  "<<i+1<<" ";
        cout<<endl<<"| ";
        for(int i=0;i<n;i++){
            cout<<torf[board[i]]<<" | ";
        }
        cout<<"\n\nNumber of moves: "<<movecount<<endl;
        cout<<"Enter the space of the toad/frog you want to move: ";
        cin>>input;
        if(input>=1 && input<=n && board[input-1]!=3){
            if(board[input-1]==1){
                if(board[input]==3){
                    moves[movecount]=input;
                    movecount++;
                    swap(board[input-1],board[input]);
                }
                else if(board[input+1]==3){
                    moves[movecount]=input+1;
                    movecount++;
                    swap(board[input-1],board[input+1]);
                }
                else
                    cout<<"\nIllegal move. Please try again."<<endl;
            }
            else{
                if(board[input-2]==3){
                    moves[movecount]=input-2;
                    movecount++;
                    swap(board[input-1],board[input-2]);
                }
                else if(board[input-3]==3){
                    moves[movecount]=input-3;
                    movecount++;
                    swap(board[input-1],board[input-3]);
                }
                else
                    cout<<"\nIllegal move. Please try again."<<endl;
            }
        }
        else if(input==0){
            if(movecount==0)
                cout<<"\nIllegal move. Please try again."<<endl;
            else{
                for(int i=0;i<n;i++){
                    if(board[i]==3){
                        swap(board[i],board[moves[movecount-1]]);
                    }
                }
                movecount--;
            }
        }

        else
            cout<<"\nIllegal move. Please try again."<<endl;
        boolean=1;
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(board[i]!=2)
                    boolean=0;
            }
            else if(i>n/2){
                if(board[i]!=1)
                    boolean=0;
            }
        }
        if(boolean==1){
            break;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
            cout<<"  "<<i+1<<" ";
        cout<<endl<<"| ";
        for(int i=0;i<n;i++){
            cout<<torf[board[i]]<<" | ";
        }
    cout<<"\nYou got it in "<<movecount<<" moves."<<endl;
}
