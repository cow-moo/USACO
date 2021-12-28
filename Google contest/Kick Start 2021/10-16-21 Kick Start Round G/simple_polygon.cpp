#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long n, a;
        cin >> n >> a;

        cout << "Case #" << z << ": ";
        if (a < n - 2)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        else
            cout << "POSSIBLE" << endl;

        for (int i = 0; i < n / 2; i++)
        {
            cout << i << " " << (i == 0 ? 0 : 1 - (i % 2)) << endl;
        }
        if (n % 2 == 1)
        {
            cout << n / 2 << " " << 4 << endl;
        }
        for (int i = n / 2 - 1; i > 0; i--)
        {
            cout << i << " " << 2 - (i % 2) << endl;
        }
        cout << "0 " << a - (n - 3) << endl;
    }
}
