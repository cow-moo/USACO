#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200050

long long capacities[MAXN];
vector<int> adj[MAXN];
int visible[MAXN];

void dfs(int cur)
{
    visible[cur] = 1;
    for (int n : adj[cur])
    {
        if (visible[n] == 0)
            dfs(n);
        visible[cur] += visible[n];
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> capacities[i];
            visible[i] = 0;
            adj[i].clear();
        }

        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            x--; y--;
            if (capacities[x] < capacities[y])
            {
                adj[y].push_back(x);
            }
            else if (capacities[x] > capacities[y])
            {
                adj[x].push_back(y);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (visible[i] == 0)
                dfs(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, visible[i]);
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
