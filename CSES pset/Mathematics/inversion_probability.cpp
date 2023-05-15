#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int arr[105];

long long roundd(long double x)
{
    long long floor = x;
    long double frac = x - floor;
    if (frac > 0.5 || (frac == 0.5 && floor % 2 == 1))
    {
        floor++;
    }
    return floor;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int num = (max(arr[i], arr[j]) - arr[j]) * arr[j] + min(arr[i], arr[j]) * (min(arr[i], arr[j]) - 1) / 2;
            int denom = arr[i] * arr[j];
            ans += (long double)num / denom;
        }
    }
    //cout << fixed << setprecision(12) << ans << endl;
    cout << fixed << setprecision(6);
    //cout << ans << endl;
    cout << roundd(ans * 1000000) / 1000000.0 << endl;
}