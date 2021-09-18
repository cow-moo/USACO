#include <iostream>
#include <set>
using namespace std;

set<pair<long long, long long> > sets;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        sets.clear();
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            long long a, b;
            cin >> a >> b;
            sets.insert({a, b});
        }

        cout << "Case #" << z << ": ";
        for (int i = 0; i < m; i++)
        {
            long long s;
            cin >> s;

            set<pair<long long, long long> >::iterator next = sets.upper_bound({s, (long long)(2e18)});
            set<pair<long long, long long> >::iterator prev = next;
            prev--;

            if (next != sets.begin() && prev->first <= s && prev->second >= s)
            {
                cout << s << " ";
                long long a = prev->first;
                long long b = prev->second;

                sets.erase(prev);
                //(prev->second) =
                if (a <= s - 1)
                    sets.insert({a, s - 1});
                if (s + 1 <= b)
                    sets.insert({s + 1, b});
            }
            else if (next == sets.begin() || (next != sets.end() && (next->first - s) < (s - prev->second)))
            {
                cout << next->first << " ";

                if (next->first == next->second)
                    sets.erase(next);
                else
                {
                    pair<long long, long long> n = {next->first + 1, next->second};
                    sets.erase(next);
                    sets.insert(n);
                }
                //next->first++;

            }
            else
            {
                cout << prev->second << " ";
                if (prev->first == prev->second)
                    sets.erase(prev);
                else
                {
                    pair<long long, long long> n = {prev->first, prev->second - 1};
                    sets.erase(prev);
                    sets.insert(n);
                }
                //prev->second--;

            }

        }
        cout << endl;
    }
}
