#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN], rev[MAXN], order;
bool visited[MAXN];
int components[MAXN];

void dfs1(int cur)
{
    visited[cur] = true;
    for (int next : adj[cur])
    {
        if (visited[next])
            continue;
        dfs1(next);
    }
    order.push_back(cur);
}

void dfs2(int cur, int num)
{
    components[cur] = num;
    for (int next : rev[cur])
    {
        if (components[next])
            continue;
        dfs2(next, num);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs1(i);
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {   
        if (components[order[i]] == 0)
            dfs2(order[i], ++cnt);
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << components[i] << " ";
    }
    cout << endl;
}