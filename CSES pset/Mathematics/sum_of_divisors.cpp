#include <iostream>
using namespace std;
#define MOD 1000000007ll
#define HALF 500000004ll

int main()
{
    long long n;
    cin >> n;

    long long ans = n % MOD;
    long long prev = n % MOD;
    for (long long i = 2; i * i <= n; i++)
    {
        long long cur = n / i % MOD;
        ans += cur * i;
        ans %= MOD;

        long long temp = prev - cur % MOD;
        if (temp < 0)
            temp += MOD;
        temp = temp * (prev + cur + 1) % MOD;
        temp = temp * HALF % MOD;
        temp = temp * (i - 1) % MOD;
        ans += temp;
        if (ans >= MOD)
            ans -= MOD;
        prev = cur;
    }
    long long i = n / prev;
    ans += i * (prev * (prev + 1) / 2 - i * (i + 1) / 2);
    cout << ans % MOD << endl;
}