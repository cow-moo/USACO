#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long inf = 1e16;
struct Entry
{
    long long dp[2][2];
    Entry()
    {
        dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = inf;
    }
};

struct SegTree
{
    int n;
    vector<Entry> bits;
    SegTree(int n) : n(n), bits((n+1)*2) {}

    Entry combine(Entry a, Entry b)
    { 
        if (a.dp[1][1] == inf)
            return b;
        if (b.dp[1][1] == inf)
            return a;
        Entry res;
        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                res.dp[i][j] = min({inf, a.dp[i][1] + b.dp[0][j], a.dp[i][0] + b.dp[1][j], a.dp[i][1] + b.dp[1][j]});
            }
        }
        return res;
    }

    void update(int k, long long x)
    {
        k += n, bits[k].dp[1][1] = x, bits[k].dp[0][0] = 0;
        for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
    }

    long long query(int l, int r)
    {
        Entry resl, resr;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l & 1) resl = combine(resl, bits[l++]);
            if (!(r & 1)) resr = combine(bits[r--], resr);
        }
        return combine(resl, resr).dp[1][1];
    }
};

int main()
{
    int n;
    cin >> n;

    SegTree st(n);
    for (int i = 1; i < n; i++)
    {
        long long a;
        cin >> a;
        st.update(i, a);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        long long x;
        cin >> k >> x;
        st.update(k, x);
        cout << st.query(1, n - 1) * 2 << endl;
    }
}

