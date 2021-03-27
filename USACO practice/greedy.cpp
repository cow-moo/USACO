#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);

    int n, ans = -1, maxim = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        c = n - c;
        maxim = max(maxim, c);

        if (ans == -1)
        {
            if (maxim <= i)
            {
                ans = n - i;
            }
        }
    }

    if (ans == -1)
        ans = 0;

    cout << ans << endl;
}
