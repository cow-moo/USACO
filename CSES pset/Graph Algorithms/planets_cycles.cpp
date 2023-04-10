#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

int nxt[MAXN];
int dist[MAXN];

int dfs(int cur)
{
    if (dist[nxt[cur]] < 0)
    {
        dist[cur] = dist[nxt[cur]] - dist[cur] + 1;
        return cur == nxt[cur] ? 0 : nxt[cur];
    }
    else if (dist[nxt[cur]] == 0)
    {
        dist[nxt[cur]] = dist[cur] - 1;
        int res = dfs(nxt[cur]);
        if (res != 0)
        {
            dist[cur] = dist[nxt[cur]];
            return res == cur ? 0 : res;
        }
    }
    
    dist[cur] = dist[nxt[cur]] + 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> nxt[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 0)
            dist[i] = -1, dfs(i);
        cout << dist[i] << " ";
    }
    cout << endl;
}