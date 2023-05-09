#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005

template <class T>
struct SegTree
{
    const T def = 0;
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
        return max(a, b);
    }

    void update(int k, T x)
    {
        k += n, tree[k] = x;
        for (k >>= 1; k; k >>= 1)
            tree[k] = combine(tree[k << 1], tree[k << 1 | 1]);
    }

    T query(int l, int r = 0)
    {
        if (r == 0)
            r = n;
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
using ST = SegTree<int>;

vector<int> adj[MAXN];
int vals[MAXN];
//pos is position in heavy[i] is heavy child of i
int parent[MAXN], heavy[MAXN], pos[MAXN], depth[MAXN], head[MAXN];
int curPos = 0;

int dfs(int cur)
{
    int size = 1, heavySize = 0;
    for (int next : adj[cur])
    {
        if (next == parent[cur])
            continue;
        parent[next] = cur;
        int sz = dfs(next);
        if (sz > heavySize)
        {
            heavySize = sz;
            heavy[cur] = next;
        }
        size += sz;
    }
    return size;
}

void decompose(int cur, int h)
{
    head[cur] = h;
    pos[cur] = curPos++;
    if (heavy[cur] != 0)
    {
        depth[heavy[cur]] = depth[cur];
        decompose(heavy[cur], h);
    }
    for (int next : adj[cur])
    {
        if (next == parent[cur] || next == heavy[cur])
            continue;
        depth[next] = depth[cur] + 1;
        decompose(next, next);
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> vals[i];

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    decompose(1, 1);

    ST st(n);
    for (int i = 1; i <= n; i++)
    {
        st.tree[n + pos[i]] = vals[i];
    }
    st.init();

    for (int i = 0; i < q; i++)
    {
        int inp, a, b;
        cin >> inp >> a >> b;
        if (inp == 1)
        {
            st.update(pos[a], b);
        }
        else
        {
            int ans = 0;
            while (head[a] != head[b])
            {
                if (depth[a] < depth[b])
                    swap(a, b);
                ans = max(ans, st.query(pos[head[a]], pos[a] + 1));
                a = parent[head[a]];
            }
            if (pos[a] > pos[b])
                swap(a, b);
            ans = max(ans, st.query(pos[a], pos[b] + 1));
            cout << ans << endl;
        }
    }
}