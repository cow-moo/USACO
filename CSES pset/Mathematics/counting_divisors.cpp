#include <iostream>
#include <vector>
using namespace std;
#define SIEVE_SIZE 1000005

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

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        long long ans = 1;
        while (x > 1)
        {
            int temp = x;
            int cnt = 1;
            while (temp % spf[x] == 0)
            {
                cnt++;
                temp /= spf[x];
            }
            x = temp;
            ans *= cnt;
        }
        cout << ans << endl;
    }
}
