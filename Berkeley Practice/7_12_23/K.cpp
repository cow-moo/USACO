#include <iostream>
#include <vector>
using namespace std;
#define SIEVE_SIZE 10000000
#define MOD 1000000007

int spf[SIEVE_SIZE]; //smallest prime factor
vector<int> primes;

void sieve()
{
    //fill(isPrime + 2, isPrime + SIEVE_SIZE, true);
    for (int i = 2; i < SIEVE_SIZE; i++)
    {
        if (spf[i] == 0)
        {
            primes.push_back(i);
            spf[i] = i;
        }

        for (int j = 0; j < primes.size() && i * primes[j] < SIEVE_SIZE && primes[j] <= spf[i]; j++)
        {
            spf[i * primes[j]] = primes[j];
        }
    }
}

long long exp(long long b, long long e)
{
    long long res = 1;
    while (e)
    {
        if (e & 1)
            res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

int main()
{
    sieve();

    while (true)
    {
        int n;
        long long res = 1;
        cin >> n;
        if (n == 0)
            break;
        for (auto p : primes)
        {
            int temp = n, cnt = 0;
            while (temp)
            {
                cnt += temp / p;
                temp /= p;
            }
            cnt -= cnt % 2;
            res = res * exp(p, cnt) % MOD;
        }
        cout << res << endl;
    }
    //cout << primes.size() << endl;
    // for (auto p : primes)
    // {
    //     cout << p << endl;
    // }

    //spf can be used to find factorization
}
