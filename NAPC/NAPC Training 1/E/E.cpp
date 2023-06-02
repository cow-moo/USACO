#include <iostream>
#include <vector>
using namespace std;
#define SIEVE_SIZE 10000000

bool isPrime[SIEVE_SIZE + 1];
int spf[SIEVE_SIZE + 1];
vector<long long> primes;

void sieve()
{
    fill(begin(isPrime) + 2, end(isPrime), true);
    for (int i = 2; i  <= SIEVE_SIZE; i++) 
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= SIEVE_SIZE && primes[j] <= spf[i]; j++)
        {
            isPrime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
    }
}

long long phi(long long x)
{
    if (x == 1)
        return 1;
    long long res = x;
    bool modify = false;
    for (auto p : primes)
    {
        if (x % p == 0)
        {
            res /= p;
            res *= p - 1;
            modify = true;
            while (x % p == 0)
                x /= p;
        }
        if (p * p > x)
            break;
    }
    if (x != 1)
    {
        res /= x;
        res *= x - 1;
    }
    return res;
}

int main()
{
    sieve();
    
//cout << phi(6) << endl;

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long ans = 0;
        for (long long i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                //cout << i << " " << n / i << endl;
                ans += phi(i + 1) + (i * i != n ? phi(n / i + 1) : 0);
            }
        }
        cout << ans << endl;
    }
}
