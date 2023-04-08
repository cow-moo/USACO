#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005

vector<int> adj[MAXN];

//depth, index
pair<int, int> dfs(int cur, int prev)
{
    pair<int, int> res = {0, cur};
    for (int v : adj[cur])
    {
        if (v == prev)
            continue;

        res = max(res, dfs(v, cur));
    }
    res.first++;
    return res;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int leaf = dfs(0, -1).second;
    cout << dfs(leaf, -1).first - 1 << endl;
}