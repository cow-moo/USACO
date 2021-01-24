#include <iostream>
#include <limits>
using namespace std;

int flags[100050];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(numeric_limits<double>::digits10 + 1);

    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, l;
        cin >> n >> l;

        for (int i = 1; i <= n; i++)
        {
            cin >> flags[i];
        }
        flags[0] = 0;
        flags[n + 1] = l;

        int lflag = 0, rflag = n + 1;
        int lspeed = 1, rspeed = 1;
        double lnextflagtime = flags[1], rnextflagtime = l - flags[n];

        while (rflag - lflag > 2)
        {
            if (lnextflagtime < rnextflagtime)
            {
                lflag++;
                lspeed++;
                lnextflagtime += ((double) flags[lflag + 1] - flags[lflag]) / (double) lspeed;
            }
            else
            {
                rflag--;
                rspeed++;
                rnextflagtime += ((double) flags[rflag] - flags[rflag - 1]) / (double) rspeed;
            }
        }

        if (lnextflagtime < rnextflagtime)
        {
            cout << lnextflagtime + ((rnextflagtime - lnextflagtime) * (double) rspeed) / (double) (lspeed + rspeed + 1) << endl;
        }
        else if (lnextflagtime > rnextflagtime)
        {
            cout << rnextflagtime + ((lnextflagtime - rnextflagtime) * (double) lspeed) / (double) (lspeed + rspeed + 1) << endl;
        }
        else
        {
            cout << lnextflagtime << endl;
            //continue;
        }
    }
}
