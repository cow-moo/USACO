#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
vector<pair<int, int>> ans;
bool visited[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            if (visited[cur])
                continue;
            visited[cur] = true;

            for (int next : adj[cur])
            {
                if (!visited[next])
                {
                    ans.push_back({cur, next});
                    q.push(next);
                }
            }
        }
    }
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}