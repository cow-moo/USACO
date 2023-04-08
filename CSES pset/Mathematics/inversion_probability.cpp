#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int arr[105];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int num = (max(arr[i], arr[j]) - arr[j]) * arr[j] + min(arr[i], arr[j]) * (min(arr[i], arr[j]) - 1) / 2;
            int denom = arr[i] * arr[j];
            ans += (double)num / denom;
        }
    }
cout << fixed << setprecision(6) << ans << endl;
}