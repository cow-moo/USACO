#include <iostream>
using namespace std;

int main()
{
    for (int i = 10;i<=66;i++){
        if (i%10<=6 && i/10<=6 && i%2==1)
            cout<<i<<endl;
    }
}
