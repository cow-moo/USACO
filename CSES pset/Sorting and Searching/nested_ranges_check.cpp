#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 200005

pair<int, int> ranges[MAXN];
map<pair<int, bool>, vector<int>> pts;
multiset<int> active; //starts

bool isContained[MAXN], contains[MAXN];

bool comp(int a, int b)
{
    return ranges[a].first > ranges[b].first;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> ranges[i].first >> ranges[i].second;
        pts[make_pair(ranges[i].first, true)].push_back(i);
        pts[make_pair(ranges[i].second, false)].push_back(i);
    }

    int latestCompletion = 0;
    for (auto &p : pts)
    {
        if (p.first.second)
        {
            for (auto i : p.second)
            {
                active.insert(ranges[i].first);
            }
        }
        else
        {
            sort(p.second.begin(), p.second.end(), comp);
            // cout << p.first.first << ": ";
            // for (auto i : p.second)
            //     cout << i << " ";
            // cout << endl;
            for (auto i : p.second)
            {
                contains[i] = latestCompletion >= ranges[i].first;
                latestCompletion = max(latestCompletion, ranges[i].first);
                active.erase(active.find(ranges[i].first));
                isContained[i] = !active.empty() && (*active.begin()) <= ranges[i].first;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << isContained[i] << " ";
    cout << endl;
}