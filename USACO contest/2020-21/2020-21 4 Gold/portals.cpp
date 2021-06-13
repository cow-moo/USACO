#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define INF 10000000

struct Vertex
{
    int c, p1, p2, p3, p4;
};

Vertex network[100050];
int cycle[200050]; //cycle num of portal i
vector<int> neighbors[200050];
//vector<pair<int, int> > adj[100050];
map<int, int> adj[100050];
bool visited[100050];
int minim[100050];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 2 * n; i++)
    {
        cycle[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> network[i].c >> network[i].p1 >> network[i].p2 >> network[i].p3 >> network[i].p4;
        network[i].p1--; network[i].p2--; network[i].p3--; network[i].p4--;
        neighbors[network[i].p1].push_back(network[i].p2);
        neighbors[network[i].p2].push_back(network[i].p1);
        neighbors[network[i].p3].push_back(network[i].p4);
        neighbors[network[i].p4].push_back(network[i].p3);

        minim[i] = INF;
    }

    int cycleCount = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (cycle[i] == -1)
        {
            int cur = i;
            int prev = -1;
            do
            {
                cycle[cur] = cycleCount;
                for (int j = 0; j < 2; j++)
                {
                    if (neighbors[cur][j] != prev || (neighbors[cur][0] == neighbors[cur][1]))
                    {
                        prev = cur;
                        cur = neighbors[cur][j];
                        break;
                    }
                }
            } while (cur != i);
            cycleCount++;
        }
        //cout << i + 1 << " " << cycle[i] << endl;
    }

    for (int i = 0; i < n; i++)
    {
        int cycle1 = cycle[network[i].p1];
        int cycle2 = cycle[network[i].p3];
        if (cycle1 == cycle2)
            continue;

//        for (auto &v : adj[cycle1])
//        {
//            if (v.first == cycle2)
//            {
//                v.second = max(v.second, cycle2);
//            }
//        }
//        adj[cycle1].push_back({cycle2, network[i].c});
//        adj[cycle2].push_back({cycle1, network[i].c});
        if (adj[cycle1].find(cycle2) != adj[cycle1].end())
        {
            adj[cycle1][cycle2] = min(adj[cycle1][cycle2], network[i].c);
            adj[cycle2][cycle1] = min(adj[cycle2][cycle1], network[i].c);
        }
        else
        {
            adj[cycle1][cycle2] = network[i].c;
            adj[cycle2][cycle1] = network[i].c;
        }
    }

    int ans = 0;
    set<pair<int, int> > pq; //cost, edge
    pq.insert({0, 0});
    for (int i = 0; i < n; i++)
    {
        if (pq.empty())
            break;
        int cost = pq.begin()->first;
        int node = pq.begin()->second;
        pq.erase(pq.begin());
        //cout << node << endl;
        visited[node] = true;
        ans += cost;

        for (auto v : adj[node])
        {
            if (!visited[v.first] && v.second < minim[v.first])
            {
                pq.erase({minim[v.first], v.first});
                pq.insert({v.second, v.first});
                minim[v.first] = v.second;
            }
        }
    }

    cout << ans << endl;
}
