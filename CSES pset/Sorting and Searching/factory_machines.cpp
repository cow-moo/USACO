#include <iostream>
using namespace std;
#define MAXN 200005

long long n, t;
long long times[MAXN];

bool check(long long time)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += time / times[i];
        if (cnt >= t)
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> t;

    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }

    long long l = 0, r = 1000000000000000000;
    while (l < r)
    {
        long long m = (l + r) / 2;
        if (check(m))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << l << endl;
}