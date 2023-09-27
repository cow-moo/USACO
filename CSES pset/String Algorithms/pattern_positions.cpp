#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1000005
 
int order[2][MAXN], classes[2][MAXN], cnt[MAXN];
int n;
string str;
 
//sorts order by value in class
void countSort(int classCount)
{
    fill(cnt, cnt + classCount, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[classes[0][i]]++;
    }
    for (int i = 1; i < classCount; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        order[1][--cnt[classes[0][order[0][i]]]] = order[0][i];
    }
    swap(order[0], order[1]);
}
 
bool comp(int a, string b)
{
    return str.substr(a, b.length()) < b;
}

bool comp2(string b, int a)
{
    return str.substr(a, b.length()) > b;
}

template <class T>
struct SegTree
{
    const T def = -2; //change here (remove const to support assignment)
    int n;
    vector<T> tree;
    SegTree() = default;
    SegTree(int n) : n(n), tree(n * 2, def) {}

    void init()
    {
        for (int i = n - 1; i > 0; i--)
            tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }

    T combine(T a, T b)
    {
        if (a == -2)
            return b;
        if (b == -2)
            return a;
        return min(a, b); //change here
    }

    void update(int k, T x)
    {
        k += n, tree[k] = x;
        for (k >>= 1; k; k >>= 1)
            tree[k] = combine(tree[k << 1], tree[k << 1 | 1]);
    }

    T query(int l, int r)
    {
        T resl = def, resr = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = combine(resl, tree[l++]);
            if (r & 1)
                resr = combine(tree[--r], resr);
        }
        return combine(resl, resr);
    }
};
using ST = SegTree<long long>;
 
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> str;
    str += "`";
    n = str.length();
 
    int classCount = 27;
    for (int i = 0; i < n; i++)
    {
        order[0][i] = i;
        classes[0][i] = str[i] - '`';
    }
 
    for (int i = -1, shift = 0; shift == 0 || (1 << i) < n; i++, shift = (1 << i))
    {
        for (int j = 0; j < n; j++)
        {
            order[0][j] -= shift;
            if (order[0][j] < 0)
                order[0][j] += n;
        }
        countSort(classCount);
        classes[1][order[0][0]] = 0;
        classCount = 1;
        for (int j = 0; j < n; j++)
        {
            pair<int, int> cur = {classes[0][order[0][j]], classes[0][(order[0][j] + shift) % n]};
            pair<int, int> prev = {classes[0][order[0][j - 1]], classes[0][(order[0][j - 1] + shift) % n]};
            if (cur != prev)
                classCount++;
            classes[1][order[0][j]] = classCount - 1;
        }
        swap(classes[0], classes[1]);
    }
 
    // for (int i = 0; i < n; i++)
    // {
    //     cout << order[0][i] << " " << str.substr(order[0][i]) << endl;
    // }

    ST st(n);
    for (int i = 0; i < n; i++)
    {
        st.tree[n + i] = order[0][i];
    }
    st.init();
 
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        //cout << lower_bound(order[0], order[0] + n, s, comp) - order[0] << endl;
        //cout << str.substr(lower_bound(order[0], order[0] + n, s, comp) - order[0]) << endl;
        cout << st.query(lower_bound(order[0], order[0] + n, s, comp) - order[0], upper_bound(order[0], order[0] + n, s, comp2) - order[0]) + 1 << "\n";
        //cout << (str.substr(*lower_bound(order[0], order[0] + n, s, comp), s.length()) == s ? "YES" : "NO") << endl;
    }
}