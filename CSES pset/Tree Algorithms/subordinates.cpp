#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];
int ans[MAXN];

int dfs(int cur)
{
    int sum = 0;
    for (int v : adj[cur])
        sum += dfs(v);
    return (ans[cur] = sum) + 1;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}