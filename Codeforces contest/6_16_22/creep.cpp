#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int a, b;
        cin >> a >> b;

        for (int i = 0; i < min(a, b); i++)
        {
            cout << "01";
        }

        if (b > a)
        {
            for (int i = 0; i < b - a; i++)
                cout << 1;
        }
        else
        {
            for (int i = 0; i < a - b; i++)
                cout << 0;
        }
        cout << endl;
    }
}
