#include <iostream>
#include <vector>
using namespace std;
#define SIEVE_SIZE 5000005

bool isPrime[SIEVE_SIZE];
int spf[SIEVE_SIZE]; //smallest prime factor
vector<int> primes;
int totient[SIEVE_SIZE], depth[SIEVE_SIZE];
vector<int> children[SIEVE_SIZE];

void sieve()
{
    fill(isPrime + 2, isPrime + SIEVE_SIZE, true);
    totient[1] = 1;
    for (int i = 2; i < SIEVE_SIZE; i++)
    {
        depth[i] = depth[totient[i]] + 1;
        children[totient[i]].push_back(i);
        if (isPrime[i])
        {
            primes.push_back(i);
            spf[i] = i;
            totient[i] = i - 1;
        }

        for (int j = 0; j < primes.size() && i * primes[j] < SIEVE_SIZE && primes[j] <= spf[i]; j++)
        {
            isPrime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
            totient[i * primes[j]] = totient[i] * (primes[j] - (primes[j] != spf[i]));
        }
    }
}

int main()
{
    sieve();

    // for (int i = 1; i <= 100; i++)
    // {
    //     cout << i << ": " << depth[i] << endl;
    // }

    for (int x : children[10])
    {
        cout << x << " ";
    }
    cout << endl;
}
