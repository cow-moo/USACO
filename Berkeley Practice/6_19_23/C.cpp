#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MAXN 45

long long fruits[MAXN];
map<long long, pair<long long, long long>> s1, s2;

void setup(long long weights[], long long n, map<long long, pair<long long, long long>> &s)
{
    s[0] = {1, 0};
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, long long>> next;
        for (auto p : s)
        {
            next.push_back({p.first + weights[i], p.second.first});
        }
        for (auto p : next)
        {
            s[p.first].first += p.second;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }

    setup(fruits, n / 2, s1);
    setup(fruits + n / 2, (n + 1) / 2, s2);

    long long sum = 0;
    for (auto rit = s2.rbegin(); rit != s2.rend(); rit++)
    {
        sum += rit->second.first * rit->first;
        rit->second.second = sum;
        //cout << p.first << " " << p.second << endl;
    }

    long long cnt = 0;
    for (auto rit = s2.rbegin(); rit != s2.rend(); rit++)
    {
        cnt += rit->second.first;
        rit->second.first = cnt;
        //cout << p.first << " " << p.second << endl;
    }

    long long ans = 0;
    for (auto p : s1)
    {
        auto it = s2.lower_bound(200 - p.first);
        if (it == s2.end())
            continue;
        ans += p.second.first * it->second.second + p.first * p.second.first * it->second.first;
    }

    cout << ans << endl;

    // for (auto p : s1)
    // {
    //     cout << p.first << " " << p.second.first << " " << p.second.second << endl;
    // }
    // cout << endl;
    // for (auto p : s2)
    // {
    //     cout << p.first << " " << p.second.first << " " << p.second.second << endl;
    // }
}