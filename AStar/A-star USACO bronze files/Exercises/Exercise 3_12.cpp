#include <iostream>
using namespace std;

int main()
{
    int temp,humidity;
    cout<<"Enter the temperature in Fahrenheit"<<endl;
    cin>>temp;
    cout<<"Enter the humidity in percent"<<endl;
    cin>>humidity;

    if (temp<60)
        if (humidity<40)
            cout<<"Lucy drinks coffee";
        else
            cout<<"Lucy eats cake";
    else
        if (humidity<40)
            cout<<"Lucy drinks iced tea";
        else
            cout<<"Lucy eats ice cream";
}

