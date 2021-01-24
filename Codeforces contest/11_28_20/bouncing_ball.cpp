#include <iostream>
using namespace std;

//int residue[100050];

void solve()
{
    int n, p, k, x, y;
    string level;
    cin >> n >> p >> k >> level >> x >> y;
    p--;

    long long ans = 1e15;

    for (int i = 0; i < k && p + i < n; i++)
    {
        //residue[i] = 0;
        long long time = i * y;
        for (int j = p + i; j < n; j += k)
        {
            time += (level[j] == '0') * x;
        }

        ans = min(ans, time);

        if (k * y < x)
        {
            for (int j = p + i; j + k < n; j += k)
            {
                time += k * y - (level[j] == '0') * x;
                ans = min(ans, time);
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}
