#include <iostream>
using namespace std;
#define MOD 1000000007ll

long long fastExp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

int cnt[30];
long long fact[1000005];

int main()
{
    string str;
    cin >> str;

    fact[0] = 1;
    for (int i = 0; i < str.length(); i++)
    {
        cnt[str[i] - 'a']++;
        fact[i + 1] = fact[i] * (i + 1) % MOD;
    }

    long long ans = fact[str.length()];
    for (int i = 0; i < 26; i++)
    {
        ans = ans * fastExp(fact[cnt[i]], MOD - 2) % MOD;
    }
    cout << ans << endl;
}
