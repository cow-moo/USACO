#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000

int cowids[50050];
bool adj[55][55];
int dist[50050];
bool visited[50050];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> cowids[i];
        cowids[i]--;
        dist[i] = INF;
    }

    string str;
    for (int i = 0; i < k; i++)
    {
        cin >> str;
        for (int j = 0; j < k; j++)
        {
            adj[i][j] = (str[j] == '1');
        }
    }

    priority_queue<pair<int, int> > pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (cur.second == n - 1)
        {
            cout << -2 * cur.first + n - 1 << endl;
            return 0;
        }

        if (visited[cur.second])
            continue;
        visited[cur.second] = true;

//        if (dist[cur.second] != cur.first)
//            continue;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && adj[cowids[cur.second]][cowids[i]])
            {
                //dist[i] = ;
                //visited[i] = true;
                pq.push({cur.first - (i > cur.second ? 0 : cur.second - i), i});
            }
        }
    }

    cout << -1 << endl;
}
