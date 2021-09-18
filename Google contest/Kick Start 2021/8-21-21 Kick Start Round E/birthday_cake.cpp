#include <iostream>
using namespace std;

long long k;

long long getCuts(long long l)
{
    return (l - 1) / k + 1;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long r, c, r1, c1, r2, c2;
        cin >> r >> c >> k >> r1 >> c1 >> r2 >> c2;

        long long minExtraCuts = 10000000;
        long ans = 0;


        long long horiCuts = getCuts(c2 - c1 + 1);
        minExtraCuts = min(minExtraCuts, getCuts(c2) - horiCuts);
        minExtraCuts = min(minExtraCuts, getCuts(c - c1 + 1) - horiCuts);
        if (r1 != 1)
            ans += horiCuts;
        if (r2 != r)
            ans += horiCuts;

        long long vertiCuts = getCuts(r2 - r1 + 1);
        minExtraCuts = min(minExtraCuts, getCuts(r2) - vertiCuts);
        minExtraCuts = min(minExtraCuts, getCuts(r - r1 + 1) - vertiCuts);
        if (c1 != 1)
            ans += vertiCuts;
        if (c2 != c)
            ans += vertiCuts;

        ans += minExtraCuts;

        ans += (vertiCuts - 1) * (horiCuts) + vertiCuts * (horiCuts - 1);
        ans += (r2 - r1 + 1) * (c2 - c1 + 1) - horiCuts * vertiCuts;

        cout << "Case #" << z << ": " << ans << endl;
    }
}
/*
1
6 8 3
2 2 5 6
*/
