#include <iostream>
#include <queue>
using namespace std;

bool contains[50050][30];
vector<int> adj[50050];
bool visited[50050];
int n;

int bfs(int x, int y)
{
    for (int i = 0; i < n; i++)
        visited[i] = false;
    queue<pair<int, int> > q; //node, distance
    q.push({x, 1});

    while (!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        //cout << node << endl;

        if (node == y)
            return dist;

        if (visited[node])
            continue;

        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
                q.push({neighbor, dist + 1});
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int q;
        cin >> n >> q;

        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;

            for (int j = 0; j < 26; j++)
                contains[i][j] = false;
            for (int j = 0; j < name.length(); j++)
                contains[i][name[j] - 'A'] = true;

            adj[i].clear();
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    if (contains[i][k] && contains[j][k])
                    {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        //cout << i << " friend " << j << endl;
                        break;
                    }
                }
            }
        }

        cout << "Case #" << z << ": ";
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            //cout << "a";
            cout << bfs(x - 1, y - 1);
            if (i != q - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
}
