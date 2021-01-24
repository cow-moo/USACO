#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define MOD 998244353

vector<pair<pair<int, bool>, int> > changepts;
set<int> active;

int get_degree(long long n, long long p) { // returns the degree with which p is in n!
  int degree_num = 0;
  long long u = p;
  long long temp = n;

  while (u <= temp) {
    degree_num += temp / u;
    u *= p;
  }
  return degree_num;
}

long long degree(long long a, long long k, long long p) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k % 2) {
      res = (res * cur) % p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

long long combinations(int n, int k, long long p) {
  int num_degree = get_degree(n, p) - get_degree(n - k, p);
  int den_degree = get_degree(k, p);

  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n - k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * ti) % p;
  }
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * degree(ti, p-2, p)) % p;
  }
  return res;
}

int main()
{
    //cout << combinations(8, 4, MOD) << endl;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        changepts.push_back({{l, 0}, i});
        changepts.push_back({{r, 1}, i});
    }

    sort(changepts.begin(), changepts.end());

    long long ans = 0;
    for (auto pt : changepts)
    {
        if (pt.first.second == 0)
        {
            //ans += exp(active.size());
            if (active.size() >= k - 1)
            {
                ans += combinations(active.size(), k - 1, MOD);
            }
            if (ans >= MOD)
                ans -= MOD;

            active.insert(pt.second);
        }
        else
        {
            active.erase(pt.second);
        }
    }

    cout << ans << endl;
}
