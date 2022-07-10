#include <iostream>
#include <queue>
using namespace std;
#define MAXN 100050

//possibly guilty
bool guilty[MAXN];
bool innocent[MAXN];
bool visited[MAXN];
vector<int> edges[MAXN]; //stored as reverse edges
//who can be proven guilty by this person being guilty
vector<int> forw[MAXN];

void dfs(int v)
{

}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = 0; i < n; i++)
        {
            guilty[i] = false;
            innocent[i] = false;
            edges[i].clear();
            forw[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            edges[b - 1].push_back(a - 1);
            forw[a - 1].push_back(b - 1);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (guilty[i] || innocent[i])
                continue;
            for (int j = 0; j < n; j++)
                visited[j] = false;
            visited[i] = true;
            int cnt = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int v : edges[cur])
                {
                    if (!visited[v])
                    {
                        q.push(v);
                        visited[v] = true;
                        cnt++;
                    }
                }
            }

            if (cnt <= k)
            {
                for (int j = 0; j < n; j++)
                {
                    guilty[j] = guilty[j] | visited[j];
                }
            }
            else
            {
                innocent[i] = true;
                q.push(i);

                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();

                    for (int v : forw[cur])
                    {
                        if (!innocent[v])
                        {
                            q.push(v);
                            innocent[v] = true;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!guilty[i])
                ans++;
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
