#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MAXN 1005

map<long long, vector<pair<int, int>>> pairs;
map<long long, vector<int>> pos;

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        pos[a].push_back(i);
    }

    if (n < 4)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if (n % 4 == 0 && pos.count(n / 4) && pos[n / 4].size() >= 4)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << pos[n / 4][i] << " ";
        }
        cout << endl;
        return 0;
    }

    for (auto &p : pos)
    {
        if (p.second.size() >= 3 && pos.count(x - 3 * p.first))
        {
            for (int i = 0; i < 3; i++)
            {
                cout << p.second[i] << " ";
            }
            cout << pos[x - 3 * p.first][0] << endl;
        }
    }

    for (auto it1 = pos.begin(); it1 != pos.end(); it1++)
    {
        for (auto it2 = it1; it2 != pos.end(); it2++)
        {
            if (it2 == it1)
                continue;

            pairs[it1->first + it2->first].push_back({it1->first, it2->first});
        }
    }

    auto lit = pairs.begin();
    auto rit = pairs.rbegin();
    while (lit != pairs.end() && rit != pairs.rend() && lit->first <= rit->first)
    {
        if (lit->first + rit->first < x)
        {
            lit++;
        }
        else if (lit->first + rit->first > x)
        {
            rit++;
        }
        else
        {
            for (auto pl : lit->second)
            {
                for (auto pr : rit->second)
                {
                    if ((pl.first == pr.first || pl.first == pr.second) && pos[pl.first].size() < 2)
                        continue;
                    if ((pl.second == pr.first || pl.second == pr.second) && pos[pl.second].size() < 2)
                        continue;

                    cout << pos[pl.first].back() << " ";
                    pos[pl.first].pop_back();
                    cout << pos[pl.second].back() << " ";
                    pos[pl.second].pop_back();
                    cout << pos[pr.first].back() << " ";
                    pos[pr.first].pop_back();
                    cout << pos[pr.second].back() << endl;
                    pos[pr.second].pop_back();
                    return 0;
                }
            }
            lit++; rit++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}