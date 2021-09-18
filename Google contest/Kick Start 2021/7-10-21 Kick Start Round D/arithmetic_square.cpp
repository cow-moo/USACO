#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int g[3][3];
        cin >> g[0][0] >> g[0][1] >> g[0][2];
        cin >> g[1][0] >> g[1][2];
        cin >> g[2][0] >> g[2][1] >> g[2][2];
        int cnt = 0;

        cnt += (g[0][2] - g[0][1]) == (g[0][1] - g[0][0]);
        cnt += (g[2][2] - g[2][1]) == (g[2][1] - g[2][0]);
        cnt += (g[2][0] - g[1][0]) == (g[1][0] - g[0][0]);
        cnt += (g[2][2] - g[1][2]) == (g[1][2] - g[0][2]);

        map<int, int> m;
        if ((g[0][0] + g[2][2]) % 2 == 0)
            m[g[0][0] + g[2][2]]++;
        if ((g[0][1] + g[2][1]) % 2 == 0)
            m[g[0][1] + g[2][1]]++;
        if ((g[0][2] + g[2][0]) % 2 == 0)
            m[g[0][2] + g[2][0]]++;
        if ((g[1][0] + g[1][2]) % 2 == 0)
            m[g[1][0] + g[1][2]]++;

        int maxim = 0;
        for (pair<int, int> p : m)
        {
            maxim = max(maxim, p.second);
        }

        cout << "Case #" << z << ": " << cnt + maxim << endl;
    }
}
