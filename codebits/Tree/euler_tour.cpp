#include <iostream>
#include <set>
#include <algorithm>
#include <deque>
using namespace std;
#define MAXN 100005

set<int> adj[MAXN];
deque<int> dq;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() % 2 == 1)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    dq.push_back(1);
    for (int i = 0; i < dq.size(); i++)
    {
        dq.push_front(dq.back());
        dq.pop_back();
        if (adj[dq.front()].size() != 0)
        {
            int cur = dq.front(), prev;
            do
            {
                dq.push_back(cur);
                prev = cur;
                cur = *adj[prev].begin();
                adj[prev].erase(adj[prev].begin());
                adj[cur].erase(prev);
            } while (cur != dq.front());
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() != 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
}