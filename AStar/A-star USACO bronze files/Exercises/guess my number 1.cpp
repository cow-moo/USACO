#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int secretnumber,input,counter=0;
    secretnumber = rand()%100 + 1;
    do
    {
        cin>>input;
        if(input < secretnumber)
            cout<<"greater"<<endl;
        else if(input > secretnumber)
            cout<<"less"<<endl;
        else
            cout<<"correct!"<<endl;
        counter++;
    }while(input!=secretnumber);
    cout<<"You took "<<counter<<" tries!"<<endl;
}

