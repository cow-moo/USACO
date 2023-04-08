#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN], active;
int visited[MAXN];
bool done;

void dfs(int cur)
{
    if (done)
        return;
    active.push_back(cur);
    visited[cur] = active.size();

    for (int next : adj[cur])
    {
        if (visited[next] == 0)
        {
            dfs(next);
        }
        else if (visited[next] > 0)
        {
            cout << active.size() - visited[next] + 2 << endl;
            for (int i = visited[next] - 1; i < active.size(); i++)
            {
                cout << active[i] << " ";
            }
            cout << next << endl;
            done = true;
        }
        if (done)
            return;
    }

    visited[cur] = -1;
    active.pop_back();
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
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
        if (done)
            return 0;
    }
    if (!done)
    {
        cout << "IMPOSSIBLE" << endl;
    }
}