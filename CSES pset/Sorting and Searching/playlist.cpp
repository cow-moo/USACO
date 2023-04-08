#include <iostream>
#include <map>
using namespace std;
#define MAXN 200005

map<int, int> pre;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;

        cur = min(cur, i - pre[k] - 1) + 1;
        ans = max(ans, cur);
        pre[k] = i;
    }
    cout << ans << endl;
}