#include <iostream>
using namespace std;
#define MOD 1000000007ll

long long fastExp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;

    long long size1 = (n / 2) * (n / 2) + (n % 2 == 1 ? (n / 2) : 0);
    long long cnt1 = fastExp(2, size1);

    long long size2 = size1 * 2;
    long long cnt2 = fastExp(2, size2) - cnt1;
    if (cnt2 < 0)
        cnt2 += MOD;

    long long size4 = size2 * 2;
    long long cnt4 = fastExp(2, size4) - cnt2 - cnt1;
    if (cnt4 < 0)
        cnt4 += MOD;

    long long ans = (cnt1 + cnt2 * fastExp(2, MOD - 2) + cnt4 * fastExp(4, MOD - 2)) % MOD;
    if (n % 2)
        ans = ans * 2 % MOD;
    cout << ans << endl;
}

//4 x 4 => 2 x 2
//5 x 5 => 3 x 2, one extra in middle
//ooooo
//ooooo
//ooooo
//ooooo
//ooooo
