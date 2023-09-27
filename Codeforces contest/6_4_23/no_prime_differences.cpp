#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            int cur = 1;
            while (cur < m)
            {
                cout << cur * n + i << " ";
                cur += 2;
            }
            cur = 0;
            while (cur < m)
            {
                cout << cur * n + i << " ";
                cur += 2;
            }
            cout << "\n";
        }
    }
}