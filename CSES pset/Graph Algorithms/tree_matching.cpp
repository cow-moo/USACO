#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int ans = 0;

bool dfs(int cur, int prev)
{
    bool child = false;
    for (int next : adj[cur])
    {
        if (next == prev)
            continue;
        child = child | dfs(next, cur);
    }
    if (child)
        ans++;
    return !child;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    cout << ans << endl;
}