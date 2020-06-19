#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    srand (time(NULL));
    int matches,input,maxPick;
    string player = "Computer";
    cout<<"How many matches are on the table? ";
    cin>>matches;
    cout<<"Up to how many matches can you take at a time? ";
    cin>>maxPick;
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
        cout<<player<<": Pick 1 to "<<maxPick<<" matches to take from the table."<<endl;
        if (player == "Player"){
            cin>>input;
            if (input>=1 && input<=maxPick && input<=matches){
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
            input = rand() % maxPick + 1;
            for (int i = 1;i<=maxPick;i++){
                if ((matches-i)%(maxPick+1)==0)
                    input = i;
            }
            cout<<input<<endl;
            matches -= input;
            if (matches == 0)
                cout<<"The computer won the game!"<<endl;
            else
                player = "Player";
        }
    }while (matches > 0);

}
