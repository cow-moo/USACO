#include <iostream>
#include <stdlib.h>
using namespace std;
#define INF 10000000000

int arr[100050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        int odd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 1)
                odd++;
        }

        long long ans = INF;

        if (odd == n / 2)
        {
            //start at 1
            int cur = 1;
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 1)
                {
                    sum += abs(i - cur);
                    cur += 2;
                }
            }
            ans = min(ans, sum);
        }
        if (odd == (n + 1) / 2)
        {
            //start at 0
            int cur = 0;
            long long sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 == 1)
                {
                    sum += abs(i - cur);
                    cur += 2;
                }
            }
            ans = min(ans, sum);
        }

        if (ans == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
