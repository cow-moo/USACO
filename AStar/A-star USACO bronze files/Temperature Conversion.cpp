#include <iostream>
using namespace std;

int main()
{
    float celsius,fahrenheit;
    cout<<"Please enter the current temp in fahrenheit."<<endl;
    cin>>fahrenheit;
    celsius = (fahrenheit-32)*5/9;
    cout<<celsius;
}
