#include <iostream>
#include <vector>
using namespace std;

int n;
bool done;
vector<int> adj[100005];

int dfs(int curNode, int parentNode)
{
    if (done)
        return 0;
    int compCount = 1;
    int child = 0;
    for (int neighbor : adj[curNode])
    {
       if (neighbor != parentNode)
       {
           compCount += dfs(neighbor, curNode);
           child = neighbor;
       }
    }

    if (compCount == n / 2 && !done)
    {
        cout << curNode << " " << child << endl;
        cout << child << " " << parentNode << endl;
        done = true;
    }

    return compCount;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }

        int inp1, inp2;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> inp1 >> inp2;
            adj[inp1].push_back(inp2);
            adj[inp2].push_back(inp1);
        }

        if (n % 2 == 1)
        {
            cout << 1 << " " << adj[1][0] << endl;
            cout << 1 << " " << adj[1][0] << endl;
        }
        else
        {
            done = false;
            dfs(1, 0);
            if (!done)
            {
                cout << 1 << " " << adj[1][0] << endl;
                cout << 1 << " " << adj[1][0] << endl;
            }
        }
    }
}
