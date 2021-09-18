#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int c, d;
        cin >> c >> d;

        if (c == 0 && d == 0)
            cout << 0 << endl;
        else if (c == d || c + d == 0)
            cout << 1 << endl;
        else if ((c + d) % 2 == 0)
            cout << 2 << endl;
        else
            cout << -1 << endl;
    }
}
