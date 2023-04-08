#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long cnt = 0, ans = 0;
    for (long long i = 0; n > 0; i++, n >>= 1)
    {
        if (n & 1)
        {
            ans += cnt + (i << (i - 1)) + 1;
            cnt += 1ll << i;
        }
    }
    cout << ans << endl;
}