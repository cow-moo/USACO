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

        int diff = 0;
        int prev = -1;
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;
            if (inp != prev)
            {
                prev = inp;
                diff++;
            }
        }

        if (diff == 1)
        {
            cout << 1 << endl;
        }
        else if (k == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << (diff - 2) / (k - 1) + 1 << endl;
        }
    }
}
