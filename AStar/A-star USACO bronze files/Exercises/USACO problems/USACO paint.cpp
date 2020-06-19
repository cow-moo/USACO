#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d,dist;
    cin>>a>>b>>c>>d;
    if (a>c){
        swap(a,c);
        swap(b,d);
    }
    if (d>b)
        dist = d-a;
    else
        dist = b-a;
    if (c>b)
        dist -= c-b;
    cout<<dist;
}
