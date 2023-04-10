#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1 || b == 1)
        {
            cout << 1 << endl;
        }
        else if (a < b)
        {
            cout << 2 << endl;
            cout << a - 1 << " " << a << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << b << " " << b - 1 << endl;
        }
        cout << a << " " << b << endl;
    }
}