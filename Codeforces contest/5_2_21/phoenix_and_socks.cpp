#include <iostream>
#include <stdlib.h>
using namespace std;

int sockCount[200050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, l, r;
        cin >> n >> l >> r;

        for (int i = 0; i < n; i++)
            sockCount[i] = 0;

        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;

            if ((i < l && l >= r) || (i >= l && l < r))
                sockCount[c - 1]++;
            else
                sockCount[c - 1]--;
        }
//        for (int i = 0; i < n; i++)
//            cout << sockCount[i] << " ";
//        cout << endl;

        int diff = abs(l - r) / 2;

        int ans = 0, lSocks = 0, rSocks = 0;
        for (int i = 0; i < n; i++)
        {
            int num = abs(sockCount[i]);

            if (sockCount[i] > 0)
            {
                int swapped = min(diff, num / 2);
                ans += swapped;
                diff -= swapped;
                num -= 2 * swapped;
            }

            //ans += num / 2;

            if (sockCount[i] > 0)
                lSocks += num;
            else if (sockCount[i] < 0)
                rSocks += num;
        }
        //cout << lSocks << " " << rSocks << " " << ans << endl;
        ans += max(lSocks, rSocks);
        cout << ans << endl;
    }
}
