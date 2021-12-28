#include <iostream>
#include <vector>
using namespace std;
#define T pair<int, pair<int, int> >

vector<int> adj[1005];
bool active[1005];
int n;

T better(T a, T b)
{
    if (a.first >= n / 2 && b.first >= n / 2)
    {
        return a.first < b.first ? a : b;
    }
    else if (a.first >= n / 2)
        return a;
    else if (b.first >= n / 2)
        return b;
    else
        return {0, {-1, -1}};
}

//node count, min children num greater than half, node num, prev
pair<int, T > dfs(int cur, int prev)
{
    T curBest = {0, {-1, -1}};
    int nodeCount = 1;
    for (int v : adj[cur])
    {
        if (v == prev)
            continue;
        pair<int, T > res = dfs(v, cur);
        nodeCount += res.first;
        curBest = better(curBest, res.second);
    }
    curBest = better(curBest, {nodeCount, {cur, prev}});
    return {nodeCount, curBest};
}

void printChildren(int cur, int prev)
{
    cout << " " << cur;
    for (int v : adj[cur])
    {
        if (v == prev)
            continue;
        printChildren(v, cur);
    }
}

void setActive(int cur, int prev, bool b)
{
    active[cur] = b;
    for (int v : adj[cur])
    {
        if (v == prev)
            continue;
        setInactive(v, cur);
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "? " << n;
    for (int i = 1; i <= n; i++)
    {
        cout << " " << i;
    }
    cout.flush();
    int maxim;
    cin >> maxim;

    pair<int, T > res = dfs(1, 0);
    cout << "? " << res.second.first;
    printChildren(res.second.second.first, res.second.second.second);
    cout.flush();
    int inp;
    cin >> inp;

    if (inp == maxim)
    {
        for (int i = 0; i < n; i++)
            active[i] = false;
        setActive(res.second.second.first, res.second.second.second, true);
    }
    else
    {
        setActive(res.second.second.first, res.second.second.second, false);
        active[res.second.second.first] = true;
    }
}
