#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
vector<int> ans;
int visited[MAXN];
bool bad = false;

void dfs(int cur)
{
    if (visited[cur] != 0)
    {
        if (visited[cur] == 1)
            bad = true;
        return;
    }
    visited[cur] = 1;
    for (int v : adj[cur])
    {
        dfs(v);
    }
    visited[cur] = 2;
    ans.push_back(cur);
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    if (bad)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
}