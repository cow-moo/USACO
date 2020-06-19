#include <iostream>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(x>y)
        cout<<x<<endl;
    else if(x>z)
        cout<<x<<endl;
    if(y>x)
        cout<<y<<endl;
    else if(y>z)
        cout<<y<<endl;
    if(z>y)
        cout<<z<<endl;
    else if(z>x)
        cout<<z<<endl;
}
