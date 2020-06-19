#include <iostream>
using namespace std;

int main()
{
    int input,sum = 0;
    do
    {
        cin>>input;
        sum += input * input;
    }while (input!=0);
    cout<<sum;
}

