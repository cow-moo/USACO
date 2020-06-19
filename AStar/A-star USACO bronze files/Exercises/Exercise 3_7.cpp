#include <iostream>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(x>y)
        if(z<y)
            cout<<z;
        else
            cout<<y;
    else
        if(x<z)
            cout<<x;
        else
            cout<<z;
}
