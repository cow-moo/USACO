#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
#define MOD 101

vector<int> adj[MAXN];
int visited[MAXN], cnt = 1;

bool ans = false; //cycle or not

void dfs(int cur, int prev)
{
    if (visited[cur] > 0 && visited[cur] < cnt)
    {
        ans = true;
        return;
    }
    visited[cur] = cnt;

    for (int next : adj[cur])
    {
        if (next != prev && visited[next] != cnt)
            dfs(next, cur);
    }
}

int main()
{
    int x = 8;
    cout << (MOD - MOD / x) * x % MOD << endl;
    return 0;

    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int next : adj[k])
    {
        dfs(next, k);
        cnt++;
    }

    cout << (ans ? "NO" : "YES") << endl;
}

//k
//