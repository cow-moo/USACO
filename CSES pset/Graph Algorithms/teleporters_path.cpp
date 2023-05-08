#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
deque<int> dq;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // for (int i = 2; i <= n - 1; i++)
    // {
    //     if (adj[i].size() % 2 == 1)
    //     {
    //         cout << "IMPOSSIBLE" << endl;
    //         return 0;
    //     }
    // }

    int cur = 1, prev;
    while (cur != n)
    {
        dq.push_back(cur);
        prev = cur;
        if (adj[prev].size() == 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        cur = adj[prev].back();
        adj[prev].pop_back();
    }
    dq.push_back(n);

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
                if (adj[prev].size() == 0)
                {
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
                cur = adj[prev].back();
                adj[prev].pop_back();
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