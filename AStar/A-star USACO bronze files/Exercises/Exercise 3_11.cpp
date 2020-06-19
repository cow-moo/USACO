#include <iostream>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if(x<y && x<z){
        cout<<x<<endl;
        if(y<z)
            cout<<y<<endl<<z<<endl;
        else
            cout<<z<<endl<<y<<endl;
    }
    else if(y<z && y<x){
        cout<<y<<endl;
        if(x<z)
            cout<<x<<endl<<z<<endl;
        else
            cout<<z<<endl<<x<<endl;
    }
    else{
        cout<<z<<endl;
        if(x<y)
            cout<<x<<endl<<y<<endl;
        else
            cout<<y<<endl<<x<<endl;
    }
}
