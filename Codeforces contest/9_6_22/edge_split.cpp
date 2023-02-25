#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200050

vector<pair<int, int> > adj[MAXN];
bool visited[MAXN];
pair<int, int> avoid;
bool done;
bool ans[MAXN];
int cnt;

void dfs(int node, int prev, int edge)
{
    visited[node] = true;
    for (auto p : adj[node])
    {
        //if (done)
        //    return;

        if (p.first == prev || ans[p.second])
        {
            continue;
        }

        if (!visited[p.first])
            dfs(p.first, node, p.second);
        else
        {
            if (cnt == 0)
            {
                avoid = {p.first, node};
                ans[p.second] = true;
                done = true;
                cnt++;
                //return;
            }
            else if (cnt == 1)
            {
                if (avoid.first == p.first)
                    avoid.first = node;
                else if (avoid.first == node)
                    avoid.first = p.first;
                else if (avoid.second == p.first)
                    avoid.second = node;
                else if (avoid.second == node)
                    avoid.second = p.first;
                ans[p.second] = true;
                done = true;
                cnt++;
                //return;
            }
            else
            {
                if (avoid == make_pair(p.first, node) || avoid == make_pair(node, p.first))
                {
                    ans[edge] = true;
                }
                else
                {
                    ans[p.second] = true;
                }
                done = true;
                //return;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
        avoid = {-1, -1};

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u - 1].push_back({v - 1, i});
            adj[v - 1].push_back({u - 1, i});
            ans[i] = false;
        }

        //for (cnt = 0; cnt < 3; cnt++)
        //{
            for (int j = 0; j < n; j++)
                visited[j] = false;
            done = false;

            dfs(0, 0, -1);

        //    if (!done)
        //        break;
        //}

        for (int i = 0; i < m; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
}
