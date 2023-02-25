#include <iostream>
#include <algorithm>
using namespace std;

pair<int, bool> ppl[200050];

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ppl[i].first;
        ppl[i].second = s[i] == '1';
        if (ppl[i].second)
            ones++;
    }

    sort(ppl, ppl + n);

    int ans = ones;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += ppl[i].second;
        if (i < n - 1 && ppl[i + 1].first == ppl[i].first)
            continue;
        ans = max(ans, i + 1 - cur + ones - cur);
    }
    cout << ans << endl;
}