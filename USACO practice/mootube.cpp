#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int parent[100050];
int sizes[100050];
int ans[100050];
vector<pair<pair<int, bool>, pair<int, int> > > events;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sizes[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        events.push_back({{-r, 0}, {p, q}});
    }

    for (int i = 0; i < q; i++)
    {
        int k, v;
        cin >> k >> v;
        events.push_back({{-k, 1}, {v, i}});
    }

    sort(events.begin(), events.end());

    for (auto event : events)
    {
        if (event.first.second)
        {
            ans[event.second.second] = sizes[find_set(event.second.first)];
        }
        else
        {
            union_sets(event.second.first, event.second.second);
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] - 1 << endl;
    }
}
