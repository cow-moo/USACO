#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 300050

int h[MAXN], s[MAXN], e[MAXN];
vector<pair<int, int> > changepts;
//happiness, index
set<pair<int, int> > cur;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return ((a.second == 0) ? s[a.first] : e[a.first]) < ((b.second == 0) ? s[b.first] : e[b.first]);
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int d, n, k;
        cin >> d >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> h[i] >> s[i] >> e[i];
            e[i]++;
            changepts.push_back({i, 0});
            changepts.push_back({i, 1});
        }
        //cout << comp({1, 0}, {3, 1}) << endl;
        sort(changepts.begin(), changepts.end(), comp);

        for (int i = 0; i < k; i++)
        {
            cur.insert({0, i});
        }

        auto kth = cur.begin();
        long long curSum = 0;
        long long ans = 0;

        for (int i = 0; i < changepts.size(); i++)
        {
            pair<int, int> temp = {h[changepts[i].first], changepts[i].first};
            if (changepts[i].second == 0)
            {
                cur.insert(temp);
                if (temp > *kth)
                {
                    curSum -= kth->first;
                    curSum += temp.first;
                    kth++;
                }
            }
            else
            {
                if (temp >= *kth)
                {
                    kth--;
                    curSum += kth->first;
                    curSum -= temp.first;
                }
                cur.erase(temp);
            }

//            cout << (*kth).first << " " << (*kth).second << endl;
//            for (auto p : cur)
//            {
//                cout << p.first << " " << p.second << endl;
//            }
//            cout << endl;

            if (i == changepts.size() - 1 || comp(changepts[i], changepts[i + 1]))
            {
                //cout << curSum << endl;
                ans = max(ans, curSum);
            }
        }

        cout << "Case #" << z << ": " << ans << endl;

        changepts.clear();
        cur.clear();
    }
}
/*
1
10 4 2
800 2 8
1500 6 9
200 4 7
400 3 5

2 9
6 10
4 8
3 6
*/
