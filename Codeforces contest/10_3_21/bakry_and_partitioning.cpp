#include <iostream>
#include <vector>
using namespace std;

int values[100050];
vector<int> adj[100050];
int counter;

int dfs(int cur, int prev, int goal)
{
    int remainder = values[cur];
    for (int v : adj[cur])
    {
        if (v == prev)
            continue;
        //int res = dfs(v, cur, goal);
        //if (res != goal)
        //    remainder ^= res;
        //else
        //    counter++;
        remainder ^= dfs(v, cur, goal);
    }
    if (remainder == goal)
    {
        counter++;
        remainder = 0;
    }
    return remainder;
}

int main()
{
    //cout << (6 ^ 1 ^ 1 ^ 2) << endl;
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, k;
        cin >> n >> k;
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
            total ^= values[i];
            adj[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //cout << "total " << total << endl;
        counter = 0;
        //if (total == 0 || (k > 2 && dfs(0, -1, total) == total && counter > 0))
        if (total == 0 || (k > 2 && dfs(0, -1, total) == 0 && counter > 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
