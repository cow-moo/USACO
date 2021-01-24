#include <iostream>
using namespace std;

pair<int, int> robbers[2050];
pair<int, int> lights[2050];
int maxy[1000010];

int main()
{
    int n, m;
    cin >> n >> m;

    int minx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> robbers[i].first >> robbers[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> lights[i].first >> lights[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (robbers[i].first <= lights[j].first)
            {
                maxy[lights[j].first - robbers[i].first] = max(maxy[lights[j].first - robbers[i].first], lights[j].second - robbers[i].second + 1);
            }
        }
    }

    int ans = 2000010;
    int curMax = 0;
    for (int i = 1000000; i >= 0; i--)
    {
        curMax = max(curMax, maxy[i]);
        ans = min(ans, i + curMax);
    }
    cout << ans << endl;
}
