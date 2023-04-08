#include <iostream>
using namespace std;
#define MAXN 200005

int n, k;
long long arr[MAXN];

bool check(long long maxSum)
{
    long long cnt = 0;
    long long curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];
        if (curSum > maxSum)
        {
            curSum = arr[i];
            cnt++;
        }
    }
    if (curSum > 0)
        cnt++;
    //cout << maxSum << " " << cnt << endl;
    return cnt <= k;
}

int main()
{
    cin >> n >> k;

    long long l = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        l = max(l, arr[i]);
    }

    long long r = 1000000000000000;
    while (l < r)
    {
        long long m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
}