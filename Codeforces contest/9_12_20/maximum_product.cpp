#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100005];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        //0 5
        //2 3
        //4 1
        int negCount = 0, posCount = 0, zeroCount = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < 0)
                negCount++;
            else if (arr[i] == 0)
                zeroCount++;
            else
                posCount++;
        }

        long long ans = 1;
        if ((negCount >= 0 && posCount >= 5) || (negCount >= 2 && posCount >= 3) || (negCount >= 4 && posCount >= 1))
        {
            sort(arr, arr + n);
            ans *= arr[--n];

            long long prod1 = 1;
            for (int i = 0; i < 4; i++)
                prod1 *= arr[i];

            long long prod2 = arr[0] * arr[1] * arr[n - 1] * arr[n - 2];

            long long prod3 = 1;
            for (int i = 0; i < 4; i++)
                prod3 *= arr[n - 1 - i];

            ans *= max(prod1, max(prod2, prod3));
        }
        else
        {
            if (zeroCount > 0)
            {
                ans = 0;
            }
            else
            {
                //only 1 4
                //3 2
                //>=5 0
                if (n == 5)
                {
                    for (int i = 0; i < n; i++)
                        ans *= arr[i];
                }
                else
                {
                    sort(arr, arr + n);
                    for (int i = 0; i < 5; i++)
                        ans *= arr[n - 1 - i];
                }
            }
        }

        cout << ans << endl;
    }
}
