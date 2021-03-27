#include <iostream>
#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;
#define MOD 1000000007

vector<int> adj[100005];
int colors[100005];

tuple<long long, long long, long long> dfs(int node, int prev)
{
    tuple<long long, long long, long long> val = make_tuple(1, 1, 1);

    if (colors[node] != 0 && colors[node] != 1)
        get<0>(val) = 0;
    if (colors[node] != 0 && colors[node] != 2)
        get<1>(val) = 0;
    if (colors[node] != 0 && colors[node] != 3)
        get<2>(val) = 0;

    for (int v : adj[node])
    {
        if (v == prev)
            continue;

        tuple<long long, long long, long long> result = dfs(v, node);
        get<0>(val) *= get<1>(result) + get<2>(result);
        get<1>(val) *= get<0>(result) + get<2>(result);
        get<2>(val) *= get<0>(result) + get<1>(result);

        get<0>(val) %= MOD;
        get<1>(val) %= MOD;
        get<2>(val) %= MOD;
    }

    //cout << get<0>(val) << " " << get<1>(val) << " " << get<2>(val) << endl;
    return val;
}

int main()
{
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;
        colors[b - 1] = c;
    }

    tuple<long long, long long, long long> result = dfs(0, -1);
    cout << (get<0>(result) + get<1>(result) + get<2>(result)) % MOD << endl;
}
