#include <iostream>
#include <vector>
using namespace std;
#define SIEVE_SIZE 10000

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

int main()
{
    sieve();
    cout << primes.size() << endl;
    for (auto p : primes)
    {
        cout << p << endl;
    }

    //spf can be used to find factorization
}
