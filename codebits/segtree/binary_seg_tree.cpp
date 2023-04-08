#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int def = 1e9;
struct SegTree
{
    int n;
    vector<int> bits;
    SegTree(int n) : n(n), bits((n + 1) * 2, def) {}

    void build()
    {
        for (int i = n - 1; i > 0; i--)
            bits[i] = combine(bits[i << 1], bits[i << 1 | 1]);
    }

    int combine(int a, int b)
    {
        return a + b;
    }

    void update(int k, int x)
    {
        k += n, bits[k] = x;
        for (k /= 2; k; k /= 2)
            bits[k] = combine(bits[k * 2], bits[k * 2 + 1]);
    }

    int query(int l, int r)
    {
        int res = def;
        for (l += n, r += n; l <= r; l /= 2, r /= 2)
        {
            if (l & 1) 
                res = combine(res, bits[l++]);
            if (!(r & 1)) 
                res = combine(res, bits[r--]);
        }
        return res;
    }
};

/* use for query if combine is not commutative
int query(int l, int r)
{
    int resl = def, resr = def;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l & 1) resl = combine(resl, bits[l++]);
        if (!(r & 1)) resr = combine(bits[r--], resr);
    }
    return combine(resl, resr);
}
*/

//gets interval associated with index in bits array
pair<int, int> debug(SegTree st, int i)
{
    if (i >= st.n)
        return {i - st.n, i - st.n + 1};
    pair<int, int> l = debug(st, i * 2);
    pair<int, int> r = debug(st, i * 2 + 1);
    if (l.second != r.first)
        return {-1, -1};
    return {l.first, r.second};
}

void printDebug(SegTree st)
{
    for (int i = 1; i < 2 * st.n; i++)
    {
        auto res = debug(st, i);
        cout << i << ": [" << res.first << ", " << res.second << ") " << st.bits[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    
    SegTree st(n);

    for (int i = 0; i < n; i++)
    {
        cin >> st.bits[n + i];
    }
    st.build();
    printDebug(st);

    while (true)
    {
        int inp;
        cin >> inp;
        
        if (inp == 1)
        {
            int k, x;
            cin >> k >> x;
            st.update(k, x);
        }
        else if (inp == 2)
        {
            int a, b;
            cin >> a >> b;
            cout << st.query(a, b) << endl;
        }
        else if (inp == 3)
        {

        }
        else
        {
            break;
        }
    }
}