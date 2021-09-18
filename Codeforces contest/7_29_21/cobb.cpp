#include <iostream>
using namespace std;

long long arr[100050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        long long ans = 1 * 2 - k * (arr[1] | arr[2]);

        for (long long i = n; i >= 1; i--)
        {
            for (long long j = i - 1; j >= 1; j--)
            {
                if (i * j < ans)
                    break;

                ans = max(ans, i * j - k * (arr[i] | arr[j]));
            }
        }

        cout << ans << endl;
    }
}
