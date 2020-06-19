#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    srand (time(NULL));
    int matches;
    int input;
    string player = "Computer";
    cout<<"How many matches are on the table? ";
    cin>>matches;
    do
    {
        cout<<endl;
        for (int i=0;i<matches;i++){
            cout<<".";
        }
        cout<<endl;
        for (int i=0;i<matches;i++){
            cout<<"|";
        }
        cout<<"\nRemaining matches: "<<matches<<endl;
        cout<<player<<": Pick 1, 2, or 3 matches to take from the table."<<endl;
        if (player == "Player"){
            cin>>input;
            if ((input==1 || input==2 || input==3) && input<=matches){
                matches -= input;
                if (matches == 0)
                    cout<<"The player won the game!"<<endl;
                else
                    player = "Computer";
            }
            else{
                cout<<"\nIllegal move. Please try again.\n";
            }
        }
        else{
            if ((matches-1)%4==0)
                input = 1;
            else if((matches-2)%4==0)
                input = 2;
            else if((matches-3)%4==0)
                input = 3;
            else
                input = rand() % 3 + 1;
            cout<<input<<endl;
            matches -= input;
            if (matches == 0)
                cout<<"The computer won the game!"<<endl;
            else
                player = "Player";
        }
    }while (matches > 0);

}
