#include <iostream>
using namespace std;
#define MOD 1000000007LL

//length, start
long long dp[405][405][405];
long long fact[405];

void add(long long* arr1, long long* arr2, long long n, long long factor, int shift)
{
    for (int i = shift; i <= n; i++)
    {
        arr1[i] += arr2[i - shift] * factor;
        //arr1[i] %= MOD;
        if (arr1[i] >= MOD)
            arr1[i] -= MOD;
        else if (arr1[i] < 0)
            arr1[i] += MOD;
    }
}

void reset(long long* arr, int n)
{
    for (int i = 0; i <= n; i++)
        arr[i] = 0;
}

void print(long long* arr, int n)
{
    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";
}

long long fastexp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res *= base;
            res %= MOD;
        }
        base = base * base;
        base %= MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long num)
{
    return fastexp(num, MOD - 2);
}

int main()
{
//    long long test1[2][3] = {{1, 2, 3}, {4, 5, 6}};
//    add(test1[0], test1[1], 2, 1, 0);
//    for (int i = 0; i < 3; i++)
//        cout << test1[0][i] << endl;
    fact[0] = 1;
    for (int i = 1; i <= 405; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        string str;
        cin >> n >> str;

        for (int i = 0; i <= n; i++)
        {
            dp[0][i][0] = 1;
            dp[1][i][1] = 1;
            dp[1][i][0] = 1;
        }

        //add(dp[2][3], dp[0][4], 2, 1, 2);
        //print(dp[2][3], 2);

        //print(dp[i][j], i);
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                reset(dp[i][j], i);
                add(dp[i][j], dp[i - 1][j], i, 1, 0);
                add(dp[i][j], dp[i - 1][j + 1], i, 1, 0);
                add(dp[i][j], dp[i - 2][j + 1], i, -1, 0);
                if (str[j] == str[j + i - 1])
                {
                    add(dp[i][j], dp[i - 2][j + 1], i, 1, 2);
                }

//                cout << i << ", " << j << ": ";
//                print(dp[i - 1][j], i);
//                cout << "|";
//                print(dp[i - 1][j + 1], i);
//                cout << "|";
//                print(dp[i - 2][j + 1], i);
//                cout << "|";
//                print(dp[i][j], i);
//                cout << endl;
            }
        }

//        for (int i = 0; i <= n; i++)
//        {
//            cout << i << ": " << dp[n][0][i] << " " << fact[i] << endl;
//        }

        long long num = 0;
        //long long fact = 1;
        for (int i = 1; i <= n; i++)
        {
            //num += fact * dp[n][0][n - i];
            //fact *= (i + 1);
            long long temp = dp[n][0][n - i];
            temp *= fact[i];
            temp %= MOD;
            temp *= fact[n - i];
            temp %= MOD;
            num += temp;//(((dp[n][0][n - i] * fact[i]) % MOD) * fact[n - i]) % MOD;

            num %= MOD;
            //fact %= MOD;
        }


//        long long denom = 1;
//        for (int i = 2; i <= n; i++)
//            denom *= i;
//        cout << denom << endl;

        //cout << modInverse(denom) << endl;
        cout << "Case #" << z << ": ";
        cout << num * modInverse(fact[n]) % MOD << endl;
//        cout << num << endl;
//        cout << fact[n] << endl;
//        cout << str.length() << endl;
//        for (int i = 0; i < MOD; i++)
//        {
//            if (i * denom % MOD == num)
//            {
//                cout << i << endl;
//                break;
//            }
//        }
    }
}
//32e6 * 8 bytes
//256e6 bytes
