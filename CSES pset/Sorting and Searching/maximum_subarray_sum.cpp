#include <iostream>
using namespace std;
#define MAXN 200005

long long arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long minim = 0, cur = 0, ans = arr[0];
    for (int i = 0; i < n; i++)
    {
        cur += arr[i];
        ans = max(ans, cur - minim);
        minim = min(minim, cur);
    }
    cout << ans << endl;
}
