#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define MAXN 100005
#define LOGN 30
 
long long order[2][MAXN], classes[LOGN][MAXN], cnt[MAXN];
long long n;

//sorts order by value in class
void countSort(int classCount, int ind)
{
    fill(cnt, cnt + classCount, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[classes[ind][i]]++;
    }
    for (int i = 1; i < classCount; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        order[1][--cnt[classes[ind][order[0][i]]]] = order[0][i];
    }
    swap(order[0], order[1]);
}
 
long long getOverlap(int a, int b)
{
    long long res = 0;
    while (true)
    {
        for (int i = 1; ; i++)
        {
            if (classes[i][a] != classes[i][b])
            {
                if (i == 1)
                {
                    return res;
                }
                else
                {
                    res += 1 << (i - 2);
                    a += 1 << (i - 2);
                    if (a >= n)
                        a -= n;
                    b += 1 << (i - 2);
                    if (b >= n)
                        b -= n;
                    break;
                }
            }
        }
    }
}

//[l, r) for range queries
template <class T, class L>
struct LazySegTree
{
    const T def = 0; //change here (remove const to support assignment)
    const L ldef = {0, false}; //change here
    int n, h;
    vector<T> tree;
    vector<L> lazy;
    LazySegTree() = default;
    LazySegTree(int n) : n(n), tree(n * 2, def), lazy(n, ldef), h(sizeof(int) * 8 - __builtin_clz(n)) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }

    T combine(T a, T b, L val = {0, false}, int len = 0)
    {
        if (val.second)
            return val.first * len;
        return a + b + val.first * len; //change here, calculate value given child intervals, lazy val, interval length
    }

    void apply(int p, L val, int len)
    {
        if (p < n)
        {
            if (val.second)
                lazy[p] = val;
            else
                lazy[p].first += val.first; //change here, propagate val to lazy[p]
        }
        tree[p] = combine(tree[p], def, val, len);
    }

    void build(int p)
    {
        int len = 1;
        while (p > 1)
            p >>= 1, len <<= 1, tree[p] = combine(tree[p << 1], tree[p << 1 | 1], lazy[p], len);
    }

    void push(int p)
    {
        for (int s = h, len = 1 << (h - 1); s > 0; s--, len >>= 1)
        {
            int i = p >> s;
            if (lazy[i] != ldef)
            {
                apply(i << 1, lazy[i], len);
                apply(i << 1 | 1, lazy[i], len);
                lazy[i] = ldef;
            }
        }
    }

    void increment(int l, int r, L val)
    {
        l += n, r += n;
        push(l), push(r - 1);
        int l0 = l, r0 = r, len = 1;
        for (; l < r; l >>= 1, r >>= 1, len <<= 1)
        {
            if (l & 1)
                apply(l++, val, len);
            if (r & 1)
                apply(--r, val, len);
        }
        build(l0), build(r0 - 1);
    }

    T query(int l, int r)
    {
        l += n, r += n;
        push(l), push(r - 1);
        T resl = def, resr = def;
        for (; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, tree[l++]);
            if (r & 1)
                resr = combine(tree[--r], resr);
        }
        return combine(resl, resr);
    }
};
using LST = LazySegTree<long long, pair<long long, bool>>;
 
int main()
{
    long long k;
    string str;
    cin >> str >> k;
    str += '`';
    n = str.length();
    k = n * (n - 1) / 2 + 1 - k;
 
    int classCount = 27;
    for (int i = 0; i < n; i++)
    {
        order[0][i] = i;
        classes[0][i] = str[i] - '`';
    }
 
    for (int i = 0, shift = 0; shift < n; i++, shift = (1 << i >> 1))
    {
        for (int j = 0; j < n; j++)
        {
            order[0][j] -= shift;
            if (order[0][j] < 0)
                order[0][j] += n;
        }
        countSort(classCount, i);
        classes[i + 1][order[0][0]] = 0;
        classCount = 1;
        for (int j = 0; j < n; j++)
        {
            pair<int, int> cur = {classes[i][order[0][j]], classes[i][(order[0][j] + shift) % n]};
            pair<int, int> prev = {classes[i][order[0][j - 1]], classes[i][(order[0][j - 1] + shift) % n]};
            if (cur != prev)
                classCount++;
            classes[i + 1][order[0][j]] = classCount - 1;
        }
    }

    LST lst(n);
    for (int i = n - 1; i > 0; i--)
    {
        int overlap = getOverlap(order[0][i], order[0][i - 1]);
        lst.increment(0, n - order[0][i], {1, false});
        long long sum = lst.query(overlap + 1, n - order[0][i]);
        if (k - sum <= 0)
        {
            for (int j = n - order[0][i] - 1; j > overlap; j--)
            {
                k -= lst.query(j, j + 1);
                if (k <= 0)
                {
                    cout << str.substr(order[0][i], j) << endl;
                    return 0;
                }
            }
        }
        k -= sum;
        lst.increment(overlap + 1, n - order[0][i], {0, true});
    }
}