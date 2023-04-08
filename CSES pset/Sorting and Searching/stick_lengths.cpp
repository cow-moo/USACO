#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

int sticks[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> sticks[i];
    }

    sort(sticks, sticks + n);

    long long ans = 0;
    for (int i = 0; i < n / 2; i++)
        ans += sticks[n / 2] - sticks[i];
    for (int i = n / 2; i < n; i++)
        ans += sticks[i] - sticks[n / 2];

    cout << ans << endl;
}
