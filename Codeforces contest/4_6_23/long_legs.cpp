#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long test(long long a, long long b, long long x)
{
    if (x <= 0)
        return a + b;
    return x + (a + x) / (x + 1) + (b + x) / (x + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        //long long cur = sqrt(a + b);
        //long long ans = test(a, b, cur - 4);
        // for (int i = -3; i <= 2; i++)
        // {
        //     ans = min(ans, test(a, b, cur + i));
        // }
        // cout << ans << endl;
        long long ans = test(a, b, 1);
        for (int i = 0; i <= 100000; i++)
        {
            ans = min(ans, test(a, b, i));
        }
        cout << ans << endl;
    }
}