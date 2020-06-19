#include <iostream>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(x+y==z)
        cout<<"sum of two";
    if(x+z==y)
        cout<<"sum of two";
    if(y+z==x)
        cout<<"sum of two";
    if(x*y==z)
        cout<<"product of two";
    if(x*z==y)
        cout<<"product of two";
    if(y*z==x)
        cout<<"product of two";
}
