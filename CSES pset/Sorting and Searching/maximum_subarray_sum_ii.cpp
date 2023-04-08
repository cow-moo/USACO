#include <iostream>
#include <set>
using namespace std;
#define MAXN 200005

multiset<long long> active;
long long pre[MAXN];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    long long ans = -1000000000000000;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        pre[i] = pre[i - 1] + x;

        if (i - b - 1 >= 0)
        {
            active.erase(active.find(pre[i - b - 1]));
        }
        if (i - a >= 0)
        {
            active.insert(pre[i - a]);
            ans = max(ans, pre[i] - *active.begin());
        }
    }

    cout << ans << endl;
}