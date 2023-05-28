#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
#define MAXN 100005

pair<long long, bool> seq[MAXN];

long long solve()
{
    int n;
    cin >> n;

    long long cnt[2] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> seq[i].first >> c;
        seq[i].second = c == 'W';
        cnt[seq[i].second] += seq[i].first;
    }

    //cout << cnt[0] << " " << cnt[1] << endl;

    if (cnt[0] == 0)
        return cnt[1];
    if (cnt[1] == 0)
        return cnt[0];

    long long block[2] = {cnt[0] / gcd(cnt[0], cnt[1]), cnt[1] / gcd(cnt[0], cnt[1])};
    //cout << block[0] << " " << block[1] << endl;
    long long cur[2] = {0, 0};

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cur[seq[i].second] += seq[i].first;
        long long temp = min(cur[0] / block[0], cur[1] / block[1]);
        //cout << i << " " << temp << endl;
        if (seq[i].second == 0 && (cur[1] != block[1] * temp || cur[0] - block[0] * temp >= seq[i].first))
            continue;
        if (seq[i].second == 1 && (cur[0] != block[0] * temp || cur[1] - block[1] * temp >= seq[i].first))
            continue;
        //cout << "a" << endl;
        ans += temp > 0;
        cur[0] -= block[0] * temp;
        cur[1] -= block[1] * temp;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}

/*
3
1 B
3 W
2 B
*/