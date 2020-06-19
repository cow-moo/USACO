#include <iostream>
using namespace std;

int main()
{
    for (int i = 10;i<=55;i++){
        if (i%10<=5 && i/10<=5)
            cout<<i<<endl;
    }
}
