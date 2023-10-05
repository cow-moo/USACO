#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
#define MAXN 5005

//dp[i][j] is probability of edge j being picked when total i edges
double dp[MAXN][MAXN];

vector<int> adj[MAXN];
double prob[MAXN];

int main()
{
    cout << fixed << setprecision(10);
    //dp[1][0] = 1;
    //dp[2][0] = 0.5;

    dp[1][0] = 1;
    for (int i = 2; i < 5000; i++)
    {
        dp[i][0] = 1.0 / i;
        dp[i][1] = (i - 2.0) / i * dp[i - 2][0];
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = (j - 1.0) / i * dp[i - 2][j - 2] + (i - j - 1.0) / i * dp[i - 2][j - 1];
        }
        //3, 0 = 0 * 
    }
    //0 1 2 '3' 4 5 6
    // int temp = 6;
    // for (int i = 0; i < temp; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            adj[a - 1].push_back(b - 1);
        }

        prob[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            prob[i] = 0;
            vector<double> roads;
            for (auto v : adj[i])
            {
                roads.push_back(-prob[v]);
            }
            sort(roads.begin(), roads.end());
            for (int j = 0; j < roads.size(); j++)
            {
                prob[i] += dp[roads.size()][j] * -roads[j];
            }
        }

        cout << prob[0] << endl;
    }
}