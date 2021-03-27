#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

multimap<string, int> suffix;
int ans[100005];
string names[100005];

int firstDiff(string a, string b)
{
    for (int i = 0; ; i++)
    {
        if (i == a.length() || i == b.length() || a[i] != b[i])
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
        string name;
        cin >> name;

        for (int j = 0; j < name.length(); j++)
        {
            suffix.insert({name.substr(j, -1), i});
        }
    }

    map<string, int>::iterator prev = suffix.end();
    map<string, int>::iterator next = suffix.begin();
    for (auto it = suffix.begin(); it != suffix.end(); it++)
    {
        while (next->second == it->second && next != suffix.end())
        {
            next++;
        }

        int maxDiff = 0;
        if (prev != suffix.end())
            maxDiff = max(maxDiff, firstDiff(it->first, prev->first));
        if (next != suffix.end())
            maxDiff = max(maxDiff, firstDiff(it->first, next->first));
        ans[it->second] += it->first.length() - maxDiff;

        //cout << it->first << " " << it->second << " " << it->first.length() - maxDiff << endl;

        prev = it;
    }

//    for (pair<string, int> p : suffix)
//    {
//        cout << p.first << " " << p.second << endl;
//    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}

//compare to left and next right diff
