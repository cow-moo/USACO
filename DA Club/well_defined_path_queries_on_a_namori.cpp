#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN], cycleStart, cycleEnd;

bool dfs(int cur)
{
    visited[cur] = true;
    for (int next : adj[cur])
    {
        if (next == parent[cur])
            continue;
        if (visited[next])
        {
            cycleEnd = cur;
            cycleStart = next;
            return true;
        }
        parent[next] = cur;
        if (dfs(next))
            return true;
    }
    return false;
}

int sz[MAXN]; //can also be by rank

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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    fill(visited + 1, visited + n + 1, false);
    for (int cur = cycleEnd; cur != cycleStart; cur = parent[cur])
    {
        visited[cur] = true;
    }
    visited[cycleStart] = true;

    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            if (!visited[i] || !visited[j])
                union_set(i, j);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;

        cout << (find_set(u) == find_set(v) ? "Yes" : "No") << endl;
    }
}