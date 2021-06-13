#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

long long x[100005];
long long y[100005];

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        sort(x, x + n);
        sort(y, y + n);

        long long ypos = y[n / 2];
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += llabs(y[i] - ypos);//(y[i] > ypos) ? (y[i] - ypos) : (ypos - y[i]);
        }

        long long xmid = x[n / 2];
        for (int i = 0; i < n; i++)
        {
            x[i] -= i;
            //long long xtarget = xmid - ((int) n / 2) + i;
            //ans += llabs(x[i] - xtarget);
            ans += llabs(x[n/2] - x[i]);
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
