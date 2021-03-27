#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > edges[1010];
int maxDist[1010];
bool visited[1010];

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t ; z++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int inp;
                cin >> inp;
            }
        }

        for (int i = 0; i < 2 * n; i++)
        {
            maxDist[i] = -1;
            visited[i] = true;
            edges[i].clear();
        }

        long long timeSum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int b;
                cin >> b;
                if (b != 0)
                {
                    edges[i].push_back({n + j, b});
                    edges[n + j].push_back({i, b});

                    visited[i] = false;
                    visited[n + j] = false;

                    timeSum += b;
                }
            }
        }

        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int inp;
                cin >> inp;
            }
        }

        long long ans = 0;

        while (true)
        {
            bool done = true;
            for (int i = 0; i < 2 * n; i++)
            {
                if (visited[i] == false)
                {
                    done = false;
                    maxDist[i] = 0;
                    break;
                }
            }
            if (done)
                break;

            //for b[i][j] i is node i, j is node n + j
            while (true)
            {
                int maxNode = -1;
                for (int i = 0; i < 2 * n; i++)
                {
                    if (!visited[i] && maxDist[i] != -1)
                    {
                        if (maxNode == -1 || maxDist[i] > maxDist[maxNode])
                            maxNode = i;
                    }
                }
                if (maxNode == -1)
                    break;

                ans += maxDist[maxNode];
                visited[maxNode] = true;

                for (pair<int, int> n : edges[maxNode])
                {
                    maxDist[n.first] = max(maxDist[n.first], n.second);
                }
            }
        }

        //cout <<"A" << ans << endl;
        cout << "Case #" << z << ": " << timeSum - ans << endl;
    }
}
