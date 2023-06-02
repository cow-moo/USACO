#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define SIEVE_SIZE 10000000
#define MAXN 1000005

int spf[SIEVE_SIZE]; //smallest prime factor
vector<int> primes;
unordered_map<int, int> seen;
int sequence[MAXN];
pair<int, int> interval[MAXN];
int ans[MAXN];
bool bad = false;

void sieve()
{
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

void recurse(int l, int r, int par)
{
    if (l > r)
        return;
    if (l == r)
    {
        ans[l] = par + 1;
        return;
    }
    int res = -1;
    for (int i = 0; i + l <= r - i; i++)
    {
        if (interval[l + i].first <= l && interval[l + i].second >= r)
        {
            res = l + i;
            break;
        }
        if (interval[r - i].first <= l && interval[r - i].second >= r)
        {
            res = r - i;
            break;
        }
    }
    if (res != -1)
    {
        ans[res] = par + 1;
        recurse(l, res - 1, res);
        recurse(res + 1, r, res);
    }
    else
    {
        bad = true;
    }
}

int main()
{
    sieve();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sequence[i];

    for (int i = 0; i < n; i++)
    {
        int cur = sequence[i];
        while (cur > 1)
        {
            int p = spf[cur];
            while (spf[cur] == p)
                cur /= p;
            if (seen.count(p))
            {
                interval[i].first = max(interval[i].first, seen[p] + 1);
            }
            seen[p] = i;
        }
    }

    seen.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = sequence[i];
        interval[i].second = n - 1;
        while (cur > 1)
        {
            int p = spf[cur];
            while (spf[cur] == p)
                cur /= p;
            if (seen.count(p))
            {
                interval[i].second = min(interval[i].second, seen[p] - 1);
            }
            seen[p] = i;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << interval[i].first << " " << interval[i].second << endl;
    // }

    recurse(0, n - 1, -1);
    
    if (bad)
    {
        cout << "impossible" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}