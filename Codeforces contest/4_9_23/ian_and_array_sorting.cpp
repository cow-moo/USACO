#include <iostream>
using namespace std;
#define MAXN 300005

long long arr[MAXN];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n % 2 == 1)
        {
            cout << "YES" << endl;
            continue;
        }

        for (int i = 1; i < n - 1; i++)
        {
            long long diff = arr[i - 1] - arr[i];
            arr[i] += diff;
            arr[i + 1] += diff;
        }

        if (arr[n - 2] <= arr[n - 1])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
    }
}