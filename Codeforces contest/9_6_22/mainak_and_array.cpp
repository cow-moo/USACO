#include <iostream>
using namespace std;

int arr[2005];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] - arr[0]);
            ans = max(ans, arr[n - 1] - arr[i]);
            ans = max(ans, arr[i] - arr[(i + 1) % n]);
        }
        cout << ans << endl;
    }
}
