#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 200050

//start, end, reward
pair<pair<long long, long long>, long long> projects[MAXN];
vector<pair<long long, pair<int, bool> > > changepts;
//time, index, start/end

long long bit[MAXN * 2];

long long getMax(int i)
{
    long long res = 0;
    while (i > 0)
    {
        res = max(res, bit[i]);
        i -= (i) & -(i);
    }
    return res;
}

void addValue(int i, long long value)
{
    while (i <= MAXN * 2)
    {
        bit[i] = max(bit[i], value);
        i += (i) & -(i);
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> projects[i].first.first >> projects[i].first.second >> projects[i].second;
        changepts.push_back({projects[i].first.first, {i, false}});
        changepts.push_back({projects[i].first.second, {i, true}});
    }

    sort(changepts.begin(), changepts.end());

    int cnt = 1;
    for (int i = 0; i < changepts.size(); i++)
    {
        if (i != 0 && changepts[i].first != changepts[i - 1].first)
        {
            cnt++;
        }
        if (changepts[i].second.second)
        {
            projects[changepts[i].second.first].first.second = cnt;
        }
        else
        {
            projects[changepts[i].second.first].first.first = cnt;
        }
    }

    sort(projects, projects + n);

//    for (int i = 0; i < n; i++)
//    {
//        cout << projects[i].first.first << " " << projects[i].first.second << " " << projects[i].second << endl;
//    }

    for (int i = 0; i < n; i++)
    {
        addValue(projects[i].first.second, getMax(projects[i].first.first - 1) + projects[i].second);
    }

//    for (int i = 1; i <= 2 * n; i++)
//    {
//        cout << i << ": " << getMax(i) << endl;
//    }

    cout << getMax(2 * n) << endl;
}
