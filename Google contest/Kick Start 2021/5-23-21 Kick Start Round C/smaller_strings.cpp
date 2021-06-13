#include <iostream>
using namespace std;
#define MOD 1000000007

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;

        string fullPal = s.substr(0, n / 2);
        long long pow = 1;
        long long ans = 0;
        for (int i = (n - 1) / 2; i >= 0; i--)
        {
            fullPal += s[i];

            ans += pow * (s[i] - 'a');
            ans %= MOD;
            pow *= k;
            pow %= MOD;
        }
        cout << fullPal << endl;
        if (fullPal < s)
            ans++;

        cout << "Case #" << z << ": " << ans % MOD << endl;
     }
}
