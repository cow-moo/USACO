#include <iostream>
using namespace std;

bool check(long long k, long long n)
{
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += min(k / i, n);
    }
    //cout << k << ": " << cnt << endl;
    return cnt > n * n / 2;
}

int main()
{
    long long n;
    cin >> n;

    long long l = 0, r = n * n;
    while (l < r)
    {
        long long m = (l + r) / 2;
        if (check(m, n))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
}