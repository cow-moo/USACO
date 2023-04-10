#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int cur = 2 * n;

        for (int i = 0; i < n; i++)
        {
            cout << cur << " ";
            cur += (i % 2 == 0 ? -2 : 2) * (n - 1 - i);
        }
        cout << endl;
        cur = 1;
        for (int i = 0; i < n - 1; i++)
        {
            cout << cur << " ";
            cur += (i % 2 == 0 ? 2 : -2) * (n - 2 - i);
        }
        cout << 2 * n - 1 << endl;
    }
}