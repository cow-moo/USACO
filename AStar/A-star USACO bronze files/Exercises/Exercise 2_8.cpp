#include <iostream>
using namespace std;

int main()
{
    int current_year = 2017,birth_year,age;
    cout<<"What is your birth year?"<<endl;
    cin>>birth_year;
    age = current_year - birth_year;
    cout<<age;
}
