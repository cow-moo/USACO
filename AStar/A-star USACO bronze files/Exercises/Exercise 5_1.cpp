#include <iostream>
using namespace std;

int MyArray[21];
int main()
{
    int counter = -1;
    do
    {
        counter++;
        cin>>MyArray[counter];
    }while(MyArray[counter]!=0);
    cout<<MyArray[0];//counter/2-1];
}
