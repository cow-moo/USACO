#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN * 2], *padj = adj + MAXN;
vector<int> rev[MAXN * 2], *pRev = rev + MAXN;
vector<int> order, components[MAXN * 2];
int visited[MAXN * 2], *pvisited = visited + MAXN;
int ans[MAXN];

void dfs1(int cur)
{
    pvisited[cur] = true;
    for (int next : padj[cur])
    {
        if (pvisited[next])
            continue;
        dfs1(next);
    }
    order.push_back(cur);
}

void dfs2(int cur, int num)
{
    pvisited[cur] = num;
    components[num].push_back(cur);
    for (int next : pRev[cur])
    {
        if (pvisited[next])
            continue;
        dfs2(next, num);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        char asign, bsign;
        int a, b;
        cin >> asign >> a >> bsign >> b;
        if (asign == '-')
            a *= -1;
        if (bsign == '-')
            b *= -1;

        padj[-a].push_back(b);
        padj[-b].push_back(a);

        pRev[b].push_back(-a);
        pRev[a].push_back(-b);
    }

    for (int i = -m; i <= m; i++)
    {
        if (!pvisited[i] && i != 0)
            dfs1(i);
    }
    fill(pvisited - m, pvisited + m + 1, 0);

    int cnt = 0;
    for (int i = order.size() - 1; i >= 0; i--)
    {
        if (pvisited[order[i]] == 0)
            dfs2(order[i], ++cnt);
    }

    for (int i = 1; i <= m; i++)
    {
        if (pvisited[i] == pvisited[-i])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    int temp = m;
    fill(ans + 1, ans + m + 1, -1);
    for (int i = cnt; i >= 1; i--)
    {
        for (int node : components[i])
        {
            if (ans[abs(node)] != -1)
                break;
            ans[abs(node)] = node > 0;
            temp--;
        }
        if (temp == 0)
            break;
    }

    for (int i = 1; i <= m; i++)
    {
        cout << (ans[i] == 0 ? '-' : '+') << " ";
    }
    cout << endl;
}