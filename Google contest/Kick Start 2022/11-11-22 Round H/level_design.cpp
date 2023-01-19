#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
#define MAXN 100050

//int dp[MAXN];
map<int, int> dp;
//vector<int> cycles;
unordered_map<int, int> cycles;
bool visited[MAXN];
int permutation[MAXN];

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;

        cycles.clear();
        dp.clear();
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
            cin >> permutation[i];
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                int l = 0;
                int cur = i;
                do
                {
                    visited[cur] = true;
                    cur = permutation[cur];
                    l++;
                } while (cur != i);
                cycles[l]++;
            }
        }

//        cycles.clear();
//        cycles.push_back(3);
//        cycles.push_back(4);
//        cycles.push_back(2);
        //n = 9;

        dp[0] = -1;
        //int maxim = 0;
        for (auto p : cycles)
        {
            for (auto rit = dp.rbegin(); rit != dp.rend(); rit++)
            {
                for (int j = 1; j <= p.second; j++)
                {
                    if (dp.count(rit->first + p.first * j) == 0)
                    {
                        dp[rit->first + p.first * j] = rit->second + j;
                    }
                    else
                    {
                        dp[rit->first + p.first * j] = min(dp[rit->first + p.first * j], rit->second + j);
                    }

//                    if (dp[i + p.first * j] == -1 || dp[i] + j < dp[i + p.first * j])
//                    {
//                        dp[i + p.first * j] = dp[i] + j;
//                        maxim = max(maxim, i + p.first * j);
//                    }
                }
            }
//            for (int i = n; i >= c; i--)
//            {
//                if (i == c || dp[i - c] != -1)
//                {
//                    if (dp[i] == -1 || dp[i - c] + 1 < dp[i])
//                        dp[i] = dp[i - c] + 1;
//                }
//            }
        }

//        for (auto p : dp)
//        {
//            cout << p.first << " " << p.second << endl;
//        }

//        for (int i = 1; i <= n; i++)
//        {
//            cout << i << " " << dp[i] << endl;
//        }

        int minim = dp[n];
        for (int i = n; i >= 1; i--)
        {
            if (dp.count(i) == 0 || minim + 1 < dp[i])
            {
                dp[i] = minim + 1;
            }
            minim = min(minim, dp[i]);
        }
        cout << "Case #" << z << ": ";
        for (int i = 1; i <= n; i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
}
