#include <iostream>
#include <vector>
using namespace std;
#define SIEVE_SIZE 10000000

bool isPrime[SIEVE_SIZE];
int spf[SIEVE_SIZE]; //smallest prime factor
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

        //primes[j] in last clause might actually be j?
        for (int j = 0; j < primes.size() && i * primes[j] < SIEVE_SIZE && primes[j] <= spf[i]; j++)
        {
            isPrime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
    }
}

int main()
{
    sieve();
    for (auto p : primes)
    {
        //cout << p << endl;
        int cnt = 0;
        while (p % 2 == 0)
        {
            cnt++;
            p /= 2;
        }
        if (cnt >= 10)
            cout << p << " " << cnt << endl;
    }

    //spf can be used to find factorization
}
