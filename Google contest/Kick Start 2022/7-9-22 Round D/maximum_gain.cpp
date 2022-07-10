#include <iostream>
using namespace std;
#define MAXN 6005

long long a[MAXN], b[MAXN];
long long maxa[MAXN], maxb[MAXN]; //maxa[i] is max points selecting i elements

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
            cin >> a[i];
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        int k;
        cin >> k;

        for (int i = 1; i <= n; i++)
        {
            long long cur = 0;
            int l = 0, r = n - 1;
            for (; l < i; l++)
            {
                cur += a[l];
            }

            maxa[i] = cur;
            while (l > 0)
            {
                cur -= a[--l];
                cur += a[r--];

                maxa[i] = max(maxa[i], cur);
            }
        }

        for (int i = 1; i <= m; i++)
        {
            long long cur = 0;
            int l = 0, r = m - 1;
            for (; l < i; l++)
            {
                cur += b[l];
            }

            maxb[i] = cur;
            while (l > 0)
            {
                cur -= b[--l];
                cur += b[r--];

                maxb[i] = max(maxb[i], cur);
            }
        }

//        for (int i = 0; i <= m; i++)
//        {
//            cout << i << " " << maxb[i] << endl;
//        }

        long long ans = 0;
        for (int i = 0; i <= n; i++)
        {
            //i from a
            //k - i from b
            if (k - i > m)
                continue;
            if (k - i < 0)
                break;

            ans = max(ans, maxa[i] + maxb[k - i]);
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
