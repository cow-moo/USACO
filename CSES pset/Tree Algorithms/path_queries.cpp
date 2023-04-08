#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005
#define SIZE 200005

long long bit[SIZE];

long long sum(int i)
{
    long long sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, long long delta)
{
    while (i <= SIZE)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

long long vals[MAXN];
vector<int> adj[MAXN];
int pos[MAXN], sz[MAXN];
int cnt = 1;

void dfs(int cur, int prev)
{
    sz[cur] = 1;
    pos[cur] = cnt++;
    for (int v : adj[cur])
    {
        if (v == prev)
            continue;
        
        dfs(v, cur);
        sz[cur] += sz[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> vals[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        add(pos[i], vals[i]);
        add(pos[i] + sz[i], -vals[i]);
    }

    for (int i = 0; i < q; i++)
    {
        int a, s;
        cin >> a >> s;
        
        if (a == 1)
        {
            long long x;
            cin >> x;
            long long diff = x - vals[s];
            add(pos[s], diff);
            add(pos[s] + sz[s], -diff);
            vals[s] = x;
        }
        else
        {
            cout << sum(pos[s]) << endl;
        }
    }
}