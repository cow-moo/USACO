#include <iostream>
using namespace std;

int main()
{
    int matches,input,player=1,diffPick,boolean;
    cout<<"How many matches are on the table? ";
    cin>>matches;
    cout<<"How many different numbers do you want to pick? ";
    cin>>diffPick;
    cout<<"Enter a list of the amount of matches each player can make:"<<endl;
    int choice;
    int pickChoices[diffPick];
    for(int i=0;i<diffPick;i++)
        cin>>pickChoices[i];
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

        cout<<"Player "<<player<<": Pick ";
        for(int i=0;i<diffPick-1;i++)
            cout<<pickChoices[i]<<", ";
        cout<<"or "<<pickChoices[diffPick-1];
        cout<<" matches to take from the table."<<endl;

        cin>>input;
        boolean = 0;
        for(int i=0;i<diffPick;i++){
            if(input==pickChoices[i]){
                boolean = 1;
                break;
            }
        }
        if (boolean && input<=matches){
            matches -= input;
            if (matches == 0)
                cout<<"\nPlayer "<<player<<" won the game!"<<endl;
            else
                (player==1) ? player=2 : player=1;
        }
        else{
            cout<<"\nIllegal move. Please try again.\n";
        }
    }while (matches > 0);
}

