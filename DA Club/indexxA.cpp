#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

long long arr[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long cur = 0, sum = 0;
    for (int i = 0; i < m; i++)
    {
        cur += arr[i];
        sum += arr[i] * (i + 1);
    }
    long long ans = sum;

    for (int i = m; i < n; i++)
    {
        sum -= cur;
        cur -= arr[i - m];
        sum += arr[i] * m;
        cur += arr[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;
}