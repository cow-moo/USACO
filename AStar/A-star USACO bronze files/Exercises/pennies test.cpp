#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

int arr[100];
int score[2];
int main(){
    srand(time(NULL));
    int lower=0,upper,turn=0;
    string input;
    cout<<"Who is going first? computer or player"<<endl;
    cin>>input;
    (input=="computer") ? turn=1 : turn = 0;
    cout<<"How many boxes are there? ";
    cin>>upper;
    upper--;
    for(int i=lower;i<=upper;i++)
        arr[i]=rand()%15+1;
    cout<<endl;
    do{
        for(int i=lower;i<=upper;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        if(turn == 0){
            cout<<"Computer: left or right"<<endl;
            if((arr[upper]-max(arr[upper-1],arr[lower]))>(arr[lower]-max(arr[lower+1],arr[upper]))){
                cout<<"right"<<endl;
                score[turn] += arr[upper];
                upper--;
                turn = 1-turn;
            }
            else if((arr[upper]-max(arr[upper-1],arr[lower]))<(arr[lower]-max(arr[lower+1],arr[upper]))){
                cout<<"left"<<endl;
                score[turn] += arr[lower];
                lower++;
                turn = 1-turn;
            }
            else{
                if(arr[upper]>arr[lower]){
                    cout<<"right"<<endl;
                    score[turn]+=arr[upper];
                    upper--;
                    turn = 1-turn;
                }
                else{
                    cout<<"left"<<endl;
                    score[turn] += arr[lower];
                    lower++;
                    turn = 1-turn;
                }
            }
        }
        else if(turn == 1){
            cout<<"Computer: left or right"<<endl;
            if((arr[upper]-max(arr[upper-1],arr[lower]))>(arr[lower]-max(arr[lower+1],arr[upper]))){
                cout<<"right"<<endl;
                score[turn] += arr[upper];
                upper--;
                turn = 1-turn;
            }
            else if((arr[upper]-max(arr[upper-1],arr[lower]))<(arr[lower]-max(arr[lower+1],arr[upper]))){
                cout<<"left"<<endl;
                score[turn] += arr[lower];
                lower++;
                turn = 1-turn;
            }
            else{
                if(arr[upper]>arr[lower]){
                    cout<<"right"<<endl;
                    score[turn]+=arr[upper];
                    upper--;
                    turn = 1-turn;
                }
                else{
                    cout<<"left"<<endl;
                    score[turn] += arr[lower];
                    lower++;
                    turn = 1-turn;
                }
            }
        }
        cout<<endl<<"Player: "<<score[0]<<endl<<"Computer: "<<score[1]<<endl<<endl;
    }while(upper-lower>=0);
    if(score[0]>score[1]){
        cout<<"The player won "<<score[0]<<" to "<<score[1]<<"!"<<endl;
    }
    else if(score[1]>score[0]){
        cout<<"The computer won "<<score[1]<<" to "<<score[0]<<"!"<<endl;
    }
    else{
        cout<<"The game was a tie!"<<endl;
    }
}

