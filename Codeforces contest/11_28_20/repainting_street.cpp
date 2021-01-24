#include <iostream>
using namespace std;

pair<int, int> upTo[105]; //upto, num

void solve()
{
    for (int i = 1; i <= 100; i++)
    {
        upTo[i] = {-1, 0};
    }

    int n, k;
    cin >> n >> k;

    int color;
    for (int i = 0; i < n; i++)
    {
        cin >> color;
        //cout << "a" << i - upTo[i].first - 1 << endl;
        if (upTo[color].first >= i)
            continue;

        int num = (i - upTo[color].first - 1) / k + ((i - upTo[color].first - 1) % k != 0);
        //cout << num << endl;
        upTo[color].second += num;
        upTo[color].first += num * k;
        upTo[color].first = min(upTo[color].first, n - 1);

        if (upTo[color].first == i - 1)
            upTo[color].first = i;
        //cout << "2: " << upTo[2].first << " " << upTo[2].second << endl;
    }

    int ans = 1000000;
    for (int i = 1; i <= 100; i++)
    {
        //cout << i << " " << upTo[i].second <<endl;//+ (n - upTo[color].first - 1) / k + ((n - upTo[color].first - 1) % k != 0) << endl;
        ans = min(ans, upTo[i].second + (n - upTo[i].first - 1) / k + ((n - upTo[i].first - 1) % k != 0));
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
