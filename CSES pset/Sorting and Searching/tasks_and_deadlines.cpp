#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

int durations[MAXN];

int main()
{
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int deadline;
        cin >> durations[i] >> deadline;
        ans += deadline;
    }

    sort(durations, durations + n);

    for (long long i = 0; i < n; i++)
    {
        ans -= (n - i) * durations[i];
    }
    cout << ans << endl;
}