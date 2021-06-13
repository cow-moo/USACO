#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, k;
        cin >> n >> k;

        if (k > (n - 1) / 2)
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 1; i <= n; i++)
        {
            if (i <= 2 * k + 1)
            {
                if (i % 2 == 1)
                    cout << (i + 1) / 2 << " ";
                else
                    cout << n + 1 - i / 2 << " ";
            }
            else
            {
                cout << i - k << " ";
            }
        }
        cout << endl;
    }
}
