#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

long long arr[MAXN];

long long solve()
{
    int n, k;
    cin >> n >> k;

    long long res = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    for (int i = 2 * k; i < n; i++)
    {
        cur += arr[i];
    }
    res = cur;
    int l = 2 * k, r = n - 1;
    while (l > 0)
    {
        l -= 2;
        cur += arr[l] + arr[l + 1];
        cur -= arr[r];
        r--;
        res = max(res, cur);
    }
    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}

//10 11 12 13 15 22
//12 13 15 22
//12 13 15