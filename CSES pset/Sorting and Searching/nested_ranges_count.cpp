#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 200005
#define BIT_SIZE 400005

vector<int> coords;

struct FenwickTree
{
    int bit[BIT_SIZE];
    int cnt = 0;

    FenwickTree(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            bit[i] = 0;
        }
    }

    FenwickTree() {}

    int sum(int i)
    {
        i++;
        int sum = 0;
        while (i > 0)
        {
            sum += bit[i];
            i -= (i) & -(i);
        }
        return sum;
    }

    void add(int i, int delta)
    {
        i++;
        while (i <= BIT_SIZE)
        {
            bit[i] += delta;
            i += (i) & -(i);
        }
    }

    void insert(int val)
    {
        int i = lower_bound(coords.begin(), coords.end(), val) - coords.begin();
        add(i, 1);
        cnt++;
    }

    void erase(int val)
    {
        int i = lower_bound(coords.begin(), coords.end(), val) - coords.begin();
        add(i, -1);
        cnt--;
    }

    //counts all less than or equal to val
    int query(int val)
    {
        int i = lower_bound(coords.begin(), coords.end(), val) - coords.begin();
        return sum(i);
    }

    int query2(int val)
    {
        int i = lower_bound(coords.begin(), coords.end(), val) - coords.begin();
        return cnt - sum(i - 1);
    }
};

pair<int, int> ranges[MAXN];
map<pair<int, bool>, vector<int>> pts;
FenwickTree active, completed;

int isContained[MAXN], contains[MAXN];

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
        coords.push_back(ranges[i].first);
        coords.push_back(ranges[i].second);
    }
    sort(coords.begin(), coords.end());

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
                contains[i] = completed.query2(ranges[i].first);
                completed.insert(ranges[i].first);
                active.erase(ranges[i].first);
                isContained[i] = active.query(ranges[i].first);
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