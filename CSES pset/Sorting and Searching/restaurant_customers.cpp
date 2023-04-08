#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

pair<int, bool> times[MAXN * 2];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> times[i * 2].first >> times[i * 2 + 1].first;
        times[i * 2].second = true;
    }

    sort(times, times + 2 * n);

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (times[i].second)
            cnt++;
        else
            cnt--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
