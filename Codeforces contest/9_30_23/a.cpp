#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        long long jsum = 0, gsum = 0, jmin = 1000000000, gmax = 0, jmax = 0, gmin = 1000000000;
        for (int i = 0; i < n; i++)
        {
            long long a;
            cin >> a;
            jsum += a;
            jmin = min(jmin, a);
            jmax = max(jmax, a);
        }
        for (int i = 0; i < m; i++)
        {
            long long b;
            cin >> b;
            gsum += b;
            gmax = max(gmax, b);
            gmin = min(gmin, b);
        }

        if (k & 1)
        {
            cout << jsum + max(0ll, gmax - jmin) << endl;
        }
        else
        {
            if (jmin < gmax)
            {
                //swap jmin, gmax
                //j has gmax, jmax
                //g has gmin, jmin

                //swap min(gmin, jmin) with max(gmax, jmax)

                //j has min(gmin, jmin) and min(gmax, jmax)
                cout << jsum + min(gmin, jmin) + min(gmax, jmax) - jmin - jmax << endl;
            }
            else
            {
                //do nothing
                //jmin, jmax > gmin, gmax
                //j has jmin, jmax
                //g has gmin, gmax

                //swap gmin, jmax
                cout << jsum + gmin - jmax << endl;
            }
            
            //cout << jsum + min(0ll, gmax - jmax) << endl;
        }
    }
}