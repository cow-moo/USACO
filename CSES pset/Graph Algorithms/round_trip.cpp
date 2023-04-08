#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
int parent[MAXN];
bool done;

void dfs(int cur)
{
    if (done)
        return;
    for (int next : adj[cur])
    {
        if (done)
            return;
        if (next == parent[cur])
            continue;
        if (parent[next] != 0)
        {
            deque<int> l, r;
            int temp = cur;
            while (temp != parent[temp])
            {
                //cout << "l" << temp << endl;
                l.push_back(temp);
                temp = parent[temp];
            }
            l.push_back(temp);
            temp = next;
            while (temp != parent[temp])
            {
                //cout << "r" << temp << endl;
                r.push_back(temp);
                temp = parent[temp];
            }
            r.push_back(temp);
            while (l.size() > 1 && r.size() > 1 && l.back() == r.back())
            {
                l.pop_back(), r.pop_back();
            }
            if (l.back() != r.back())
            {
                l.push_back(parent[l.back()]);
                r.push_back(parent[r.back()]);
            }

            cout << l.size() + r.size() << endl;
            while (!l.empty())
            {
                cout << l.back() << " ";
                l.pop_back();
            }
            while (!r.empty())
            {
                cout << r.front() << " ";
                r.pop_front();
            }
            cout << endl;
            done = true;
            return;
        }
        parent[next] = cur;
        dfs(next);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == 0)
        {
            parent[i] = i;
            dfs(i);
        }
        if (done)
            return 0;
    }
    if (!done)
    {
        cout << "IMPOSSIBLE" << endl;
    }
}