#include <iostream>
using namespace std;

int main()
{
    int matches;
    int input,player=1;
    cout<<"How many matches are on the table? ";
    cin>>matches;
    do
    {
        cout<<"\nRemaining matches: "<<matches<<endl;
        cout<<"Player "<<player<<": Pick 1, 2, or 3 matches to take from the table."<<endl;
        cin>>input;
        if ((input==1 || input==2 || input==3) && input<=matches){
            matches -= input;
            if (matches == 0)
                cout<<"Player "<<player<<" won the game!"<<endl;
            else
                (player==1) ? player=2 : player=1;
        }
        else{
            cout<<"Illegal move. Please try again.\n";
        }
    }while (matches > 0);

}

