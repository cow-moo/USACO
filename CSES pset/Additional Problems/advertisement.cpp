#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

long long heights[MAXN];
bool active[MAXN];
int order[MAXN];
int parent[MAXN];
long long sz[MAXN];

bool comp(int a, int b)
{
    return heights[a] > heights[b];
}

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (sz[a] > sz[b])
    {
        swap(a, b);
    }
    parent[a] = b;
    sz[b] += sz[a];
}


int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
        make_set(i);
        order[i] = i;
    }

    sort(order, order + n, comp);

    long long longest = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        active[order[i]] = true;
        if (order[i] + 1 < n && active[order[i] + 1])
            union_set(order[i], order[i] + 1);
        if (order[i] - 1 >= 0 && active[order[i] - 1])
            union_set(order[i], order[i] - 1);
        longest = max(longest, sz[find_set(order[i])]);
        ans = max(ans, longest * heights[order[i]]);
    }
    cout << ans << endl;
}