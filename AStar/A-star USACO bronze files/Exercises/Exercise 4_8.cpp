#include <iostream>
using namespace std;

int main()
{
    int input;
    do
    {
        cin>>input;
        if (input%7==3)
            cout<<input<<endl;
    }while(input!=0);
}
