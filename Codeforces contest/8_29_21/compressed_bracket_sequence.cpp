#include <iostream>
#include <stdlib.h>
using namespace std;

long long arr[1005];

int main()
{
    int n;
    cin >> n;
    //cout << n - n % 2 << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long ans = 0;
    for (int i = 1; i < n; i += 2)
    {
        long long curSum = 0;
        long long minSum = 0;
        for (int j = i - 1; j < n - n % 2; j += 2)
        {
            if (j != i - 1)
            {
                curSum -= arr[j - 1];
                minSum = min(minSum, curSum);
                curSum += arr[j];
            }


            long long usel = abs(minSum);
            long long user = usel + curSum;

            if (arr[i - 1] < usel)
                break;
            if (arr[j + 1] < user)
                continue;

            if (usel != 0 && user != 0)
                ans++;
            //cout << i << " " << j << ": " << 1 + min(arr[i - 1] - usel, arr[j + 1] - user) << endl;
            ans += min(arr[i - 1] - usel, arr[j + 1] - user);
        }
    }

    cout << ans << endl;
}
