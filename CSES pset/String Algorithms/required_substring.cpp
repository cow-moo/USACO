#include <iostream>
using namespace std;
#define MOD 1000000007ll
#define MAXN 1005

long long choose[MAXN][MAXN];

long long fastExp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res *= base;
            res %= MOD;
        }
        base = base * base;
        base %= MOD;
        exp >>= 1;
    }
    return res;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    choose[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        choose[i][0] = 1;
        choose[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
            if (choose[i][j] >= MOD)
                choose[i][j] -= MOD;
        }
    }

    long long ans = 0;

    for (int i = 1; i <= n / s.length(); i++)
    {
        
    }
}