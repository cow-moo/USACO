#include <iostream>
#include <vector>
#include <map>
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

int colors[MAXN], flatColors[MAXN];;
vector<int> adj[MAXN], start[MAXN];
int pos[MAXN], ans[MAXN];
map<int, int> prv;
int cnt = 1;

int dfs(int cur, int prev)
{
    int sz = 1;
    pos[cur] = cnt;
    flatColors[cnt++] = colors[cur];
    for (int v : adj[cur])
    {
        if (v == prev)
            continue;
        
        sz += dfs(v, cur);
    }
    start[pos[cur] + sz - 1].push_back(cur);
    return sz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> colors[i];
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
        add(i, 1);
        if (prv.count(flatColors[i]))
        {
            add(prv[flatColors[i]], -1);
        }
        prv[flatColors[i]] = i;

        for (int cur : start[i])
        {
            ans[cur] = sum(i) - sum(pos[cur] - 1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}