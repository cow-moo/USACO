#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, m;
        cin >> n >> m;

        if (n > m)
        {
            cout << "No" << endl;
            continue;
        }
        if (n % 2 == 1)
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n - 1; i++)
            {
                cout << "1 ";
            }
            cout << m - (n - 1) << endl;
        }
        else
        {
            if (m % 2 == 1)
            {
                cout << "No" << endl;
                continue;
            }
            cout << "Yes" << endl;
            for (int i = 0; i < n - 2; i++)
            {
                cout << "1 ";
            }
            cout << m / 2 - n / 2 + 1 << " " << m / 2 - n / 2 + 1 << endl;
        }
    }
}
