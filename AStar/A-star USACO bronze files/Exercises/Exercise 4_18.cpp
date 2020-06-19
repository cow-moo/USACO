#include <iostream>
using namespace std;

int main()
{
    int secretnumber,input;
    secretnumber = 72;
    do
    {
        cin>>input;
        if(input < secretnumber)
            cout<<"greater"<<endl;
        else if(input > secretnumber)
            cout<<"less"<<endl;
        else
            cout<<"correct!"<<endl;
    }while(input!=secretnumber);
}

