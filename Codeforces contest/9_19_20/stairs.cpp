#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        long long x;
        cin >> x;
        x *= 2;

        long long sum = 0;
        long long exp = 2;
        int ans = 0;

        while (sum <= x)
        {
            sum += exp * (exp - 1);
            ans++;
            exp *= 2;
        }

        cout << ans - 1 << endl;
    }
}
