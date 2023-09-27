#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        if (a[0] == b[0])
        {
            cout << "YES\n" << a[0] << "*\n";
            continue;
        }
        if (a[a.length() - 1] == b[b.length() - 1])
        {
            cout << "YES\n*" << a[a.length() - 1] << '\n';
            continue;
        }

        bool found = false;
        for (int i = 0; i < a.length() - 1; i++)
        {
            for (int j = 0; j < b.length() - 1; j++)
            {
                if (a.substr(i, 2) == b.substr(j, 2))
                {
                    found = true;
                    cout << "YES\n*" << a.substr(i, 2) << "*\n";
                    break;
                }
            }
            if (found)
                break;
        }

        if (!found)
            cout << "NO\n";
    }
}