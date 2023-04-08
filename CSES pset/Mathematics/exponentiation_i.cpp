#include <iostream>
using namespace std;
#define MOD 1000000007

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
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        cout << fastExp(a, b) << endl;
    }
}
