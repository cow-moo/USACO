#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

string names[100005];

struct comp
{
    bool operator() (pair<int, int> a, pair<int, int> b) const
    {
        //return names[a.first].substr(a.second, -1) < names[b.first].substr(b.second, -1);
        for (int i = 0; ; i++)
        {
            if (a.second + i == names[a.first].length() || names[a.first][a.second + i] < names[b.first][b.second + i])
                return true;
            if (b.second + i == names[b.first].length() || names[a.first][a.second + i] > names[b.first][b.second + i])
                return false;
        }
    }
};

//name index, starting pos
multiset<pair<int, int>, comp> suffix;
int ans[100005];


int firstDiff(pair<int, int> a, pair<int, int> b)
{
    for (int i = 0; ; i++)
    {
        if (a.second + i == names[a.first].length() || b.second + i == names[b.first].length() || names[a.first][a.second + i] != names[b.first][b.second + i])
            return i;
    }
}

int main()
{
    freopen("standingout.in", "r", stdin);
    freopen("standingout.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> names[i];

        for (int j = 0; j < names[i].length(); j++)
        {
            suffix.insert({i, j});
        }
//        for (int j = 0; j < name.length(); j++)
//        {
//            suffix.insert({name.substr(j, -1), i});
//        }
    }

    auto prev = suffix.end();
    auto next = suffix.begin();
    for (auto it = suffix.begin(); it != suffix.end(); it++)
    {
        while (next->first == it->first && next != suffix.end())
        {
            next++;
        }

        int maxDiff = 0;
        if (prev != suffix.end())
            maxDiff = max(maxDiff, firstDiff(*it, *prev));
        if (next != suffix.end())
            maxDiff = max(maxDiff, firstDiff(*it, *next));
        ans[it->first] += names[it->first].length() - it->second - maxDiff;

        //cout << it->first << " " << it->second << " " << it->first.length() - maxDiff << endl;

        prev = it;
    }

//    for (pair<int, int> p : suffix)
//    {
//        cout << names[p.first].substr(p.second, -1) << endl;
//    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}

//compare to left and next right diff
