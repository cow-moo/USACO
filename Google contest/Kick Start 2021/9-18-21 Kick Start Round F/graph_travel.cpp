#include <iostream>
#include <set>
using namespace std;

int n;
long long ans;
long long l[20], r[20], a[20], k;
bool visited[20];
bool adj[20][20];

void dfs(long long mp)
{
    if (mp == k)
        ans++;
    if (mp >= k)
        return;
//    set<int> toVisit;
//    for (int i = 0; i < n; i++)
//    {
//        if (visited[i])
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (adj[i][j] && !visited[j] && mp >= l[j] && mp <= r[j])
//                    toVisit.insert(j);
//            }
//        }
//    }
//
//    for (int next : toVisit)
//    {
//        visited[next] = true;
//        dfs(mp + a[next]);
//        visited[next] = false;
//    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && mp >= l[i] && mp <= r[i])
        {
            bool canVisit = false;
            for (int j = 0; j < n; j++)
                canVisit = canVisit || (adj[i][j] && visited[j]);
            if (canVisit)
            {
                visited[i] = true;
                dfs(mp + a[i]);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int m;
        cin >> n >> m >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i] >> a[i];
            for (int j = 0; j < n; j++)
                adj[i][j] = false;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a][b] = true;
            adj[b][a] = true;
        }

        ans = 0;
        for (int i = 0; i < n; i++)
        {
            visited[i] = true;
            dfs(a[i]);
            visited[i] = false;
        }
        cout << "Case #" << z << ": " << ans << endl;
    }
}
