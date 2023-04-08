#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN][2];
int kingdom[MAXN];
bool visited[MAXN][2];
int dir = 0, num = 1;

void dfs(int cur)
{
    visited[cur][dir] = true;
    for (auto v : adj[cur][dir])
    {
        if (kingdom[v] == 0 && !visited[v][dir])
            dfs(v);
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
        a--; b--;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (kingdom[i] == 0)
        {
            dir = 0;
            dfs(i);
            dir = 1;
            dfs(i);
            for (int j = 0; j < n; j++)
            {
                if (visited[j][0] && visited[j][1])
                {
                    kingdom[j] = num;
                }
                visited[j][0] = visited[j][1] = 0;
            }
            num++;
        }
    }
    cout << num - 1 << endl;
    for (int i = 0; i < n; i++)
        cout << kingdom[i] << " ";
    cout << endl;
}