#include <iostream>
using namespace std;
#define MAXN 200005

int arr[MAXN];

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0, r = 0, sum = 0, ans = 0;
    while (r <= n)
    {
        if (sum < x)
            sum += arr[r++];
        else if (sum > x)
            sum -= arr[l++];
        else
            ans++, sum -= arr[l++], sum += arr[r++];
    }

    cout << ans << endl;
}
