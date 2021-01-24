#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> robbers[2050];
pair<int, int> searchlights[2050];
pair<int, int> lights[2050];
int n, m, newm;

int check(int xoffset)
{
    int maxChange = 0;
    for (int i = 0; i < n; i++)
    {
        maxChange = max(maxChange, lower_bound(lights, lights + newm, make_pair(robbers[i].first + xoffset, 0))->second - robbers[i].second);
    }
    return maxChange;
}

int main()
{
    cin >> n >> m;

    int minx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> robbers[i].first >> robbers[i].second;
        minx = min(minx, robbers[i].first);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> searchlights[i].first >> searchlights[i].second;
    }
    sort(searchlights, searchlights + m);
    newm = 0;
    for (int i = 0; i < m; i++)
    {
        while (newm > 0 && lights[newm - 1].second <= searchlights[i].second)
        {
            newm--;
        }
        lights[newm++] = searchlights[i];
    }

//    for (int i = 0; i < newm; i++)
//        cout << lights[i].first << " " << lights[i].second << endl;

    int ans = check(0);
    for (int i = 0; i < newm; i++)
    {
        if (lights[i].first - minx + 1 > 0)
        {
            ans = min(ans, check(lights[i].first - minx + 1) + lights[i].first - minx + 1);
        }
    }

    cout << ans << endl;
}
