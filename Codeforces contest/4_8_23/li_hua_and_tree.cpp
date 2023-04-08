#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 100005

long long importance[MAXN];
vector<int> adj[MAXN];
int parent[MAXN], sz[MAXN];
set<pair<int, int>> children[MAXN];

//update parent, sz, importance
void dfsInit(int cur)
{
    sz[cur] = 1;
    for (int next : adj[cur])
    {
        if (next == parent[cur])
            continue;
        parent[next] = cur;
        dfsInit(next);
        importance[cur] += importance[next];
        sz[cur] += sz[next];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> importance[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsInit(1);

    for (int i = 1; i <= n; i++)
    {
        for (int next : adj[i])
        {
            if (next == parent[i])
                continue;
            children[i].insert({-sz[next], next});
        }
    }

    for (int i = 0; i < m; i++)
    {
        int t, x;
        cin >> t >> x;

        if (t == 1)
        {
            cout << importance[x] << endl;
        }
        else
        {
            if (children[x].empty())
                continue;
            int heavyChild = children[x].begin()->second;
            int par = parent[x];
            //erase heavy child from x children
            children[x].erase(children[x].begin());
            importance[x] -= importance[heavyChild];
            //erase x from parent
            children[par].erase({-sz[x], x});
            sz[x] -= sz[heavyChild];

            sz[heavyChild] += sz[x];
            importance[heavyChild] += importance[x];
            parent[x] = heavyChild;

            children[heavyChild].insert({-sz[x], x});
            
            parent[heavyChild] = par;
            children[parent[heavyChild]].insert({-sz[heavyChild], heavyChild});
        }
    }
}