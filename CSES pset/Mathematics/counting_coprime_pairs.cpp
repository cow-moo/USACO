#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
#define SIEVE_SIZE 1000005

bool isPrime[SIEVE_SIZE];
int spf[SIEVE_SIZE], cnt[SIEVE_SIZE]; //smallest prime factor
vector<int> primes;

void sieve()
{
    fill(isPrime + 2, isPrime + SIEVE_SIZE, true);
    for (int i = 2; i < SIEVE_SIZE; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            spf[i] = i;
        }

        for (int j = 0; j < primes.size() && i * primes[j] < SIEVE_SIZE && j <= spf[i]; j++)
        {
            isPrime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
    }
}

int main()
{
    sieve();

    int n;
    cin >> n;

    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        vector<int> comb;
        comb.push_back(1);
        while (x > 1)
        {
            int p = spf[x];
            while (spf[x] == p)
                x /= p;
            for (int j = comb.size() - 1; j >= 0; j--)
            {
                comb.push_back(comb[j] * -p);
            }
        }

        for (auto c : comb)
        {
            res += c > 0 ? cnt[c] : -cnt[-c];
            cnt[abs(c)]++;
        }
    }

    cout << res << endl;
}


//42
//2, 3, 6, 7, 14, 21, 42
//+2, +3, +7, -6, -14, -21, +42
