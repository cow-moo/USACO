#include <iostream>
using namespace std;
/*
  1 2 3
1 _|_|_
2 _|_|_
3  | |

  1 2 3
1 X|_|O
2 _|X|_
3  | |O

*/
int board[3][3];//={1,2,1,0,2,0,0,1,0};
char pieces[9]={'_','X','O','_','X','O',' ','X','O'};
int scores[2];
int main(){
    int turn=0,inputx,inputy,rip=0;
    char input;
    bool quit=false;
    for(int a=0;;a++){
        while(1){
            cout<<"  1 2 3"<<endl;
            for(int i=0;i<3;i++){
                cout<<i+1<<" "<<pieces[board[i][0]+3*i]<<"|"<<pieces[board[i][1]+3*i]<<"|"<<pieces[board[i][2]+3*i]<<endl;
            }

            turn = 1-turn;
            quit = false;
            for(int i=0;i<3;i++){
                if(board[i][0]==turn+1 && board[i][1]==turn+1 && board[i][2]==turn+1){
                    cout<<endl<<"Player "<<turn+1<<" won!"<<endl;
                    quit = true;
                }
            }
            for(int i=0;i<3;i++){
                if(board[0][i]==turn+1 && board[1][i]==turn+1 && board[2][i]==turn+1){
                    cout<<endl<<"Player "<<turn+1<<" won!"<<endl;
                    quit = true;
                }
            }
            if(board[0][0]==turn+1 && board[1][1]==turn+1 && board[2][2]==turn+1){
                cout<<endl<<"Player "<<turn+1<<" won!"<<endl;
                quit = true;
            }
            if(board[0][2]==turn+1 && board[1][1]==turn+1 && board[2][0]==turn+1){
                cout<<endl<<"Player "<<turn+1<<" won!"<<endl;
                quit = true;
            }
            if(quit){
                break;
            }
            quit=true;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j]==0){
                        quit = false;
                    }
                }
            }
            if(quit){
                cout<<endl<<"The game was a tie!"<<endl;
                rip=1;
                break;
            }
            turn = 1-turn;


            cout<<"Player "<<turn+1<<"("<<pieces[turn+1]<<"): Make your move (row column)"<<endl;
            cin>>inputx>>inputy;
            if(board[inputx-1][inputy-1]==0){
                board[inputx-1][inputy-1]=turn+1;
                turn=1-turn;
            }
            else
                cout<<endl<<"Incorrect input."<<endl;
            cout<<endl;
        }
        if(rip==0)
            scores[turn]++;
        cout<<endl<<"The score is "<<scores[0]<<" to "<<scores[1]<<"."<<endl
            <<"Do you want to play again? Y or N"<<endl;
        cin>>input;
        if(input=='y' || input=='Y'){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++)
                    board[i][j]=0;
            }
            turn=a%2 + 1;
            rip=0;
            cout<<endl;
        }
        else{
            cout<<endl;
            if(scores[0]>scores[1])
                cout<<"Player 1 won by "<<scores[0]-scores[1]<<" point(s)."<<endl;
            else if(scores[1]>scores[0])
                cout<<"Player 2 won by "<<scores[1]-scores[0]<<" point(s)."<<endl;
            else
                cout<<"Nobody won."<<endl;
            break;
        }
    }
}
