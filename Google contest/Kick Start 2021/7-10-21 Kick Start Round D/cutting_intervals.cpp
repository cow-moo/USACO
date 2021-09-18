#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long n, c;
        cin >> n >> c;

        //vector<pair<int, bool> > changepts;
        map<pair<long long, bool>, long long> changepts;

        for (long long i = 0; i < n; i++)
        {
            long long l, r;
            cin >> l >> r;

            changepts[{l, 1}]++;
            changepts[{r, 0}]++;
//            changepts.push_back({l, 1});
//            changepts.push_back({r, 0});
        }

        //sort(changepts.begin(), changepts.end());

        map<long long, long long> m;
        long long cur = 0, prev = -100;
        for (auto p : changepts)
        {
            //cout << p.first.first << " " << p.first.second << ": " << p.second << endl;
            if (p.first.second == 0)
            {
                m[-cur] += max(p.first.first - prev - 1, 0ll);
                cur -= p.second;
                m[-cur]++;
            }
            if (p.first.second == 1)
            {
                m[-cur] += p.first.first - prev;
                cur += p.second;
            }
            prev = p.first.first;
            //cout << "cur: " << cur << endl;
        }

        long long ans = n;
        for (auto p : m)
        {
            long long used = min(p.second, c);
            ans -= p.first * used;
            c -= used;

            if (c == 0)
                break;
            //cout << p.first << " " << p.second << endl;
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
