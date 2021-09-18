#include <iostream>
#include <vector>
#include <set>
#include <list>
using namespace std;
#define MAXN 1005

int parent[MAXN][2];
int sz[MAXN][2]; //can also be by rank
vector<list<int> > sets;

void make_set(int v, int x)
{
    parent[v][x] = v;
    sz[v][x] = 1;
}

int find_set(int v, int x)
{
    if (parent[v][x] == v)
        return v;
    return parent[v][x] = find_set(parent[v][x], x);
}

void union_set(int a, int b, int x)
{
    a = find_set(a, x);
    b = find_set(b, x);
    if (sz[a][x] > sz[b][x])
    {
        swap(a, b);
    }
    if (x == 0)
    {
        sets[b].splice(sets[a]);
    }
    parent[a][x] = b;
    sz[b][x] += sz[a][x];
}

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    for (int i = 0; i < n; i++)
    {
        make_set(i, 0);
        make_set(i, 1);
        list<int> l;
        l.push_back(i);
        sets.push_back(l);
    }

    for (int i = 0; i < m1; i++)
    {
        int a, b;
        cin >> a >> b;
        union_set(a - 1, b - 1, 0);
    }

    for (int i = 0; i < m2; i++)
    {
        int a, b;
        cin >> a >> b;
        union_set(a - 1, b - 1, 1);
    }

    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (find_set(i, 0) != find_set(j, 0) && find_set(i, 1) != find_set(j, 1))
            {
                ans.push_back({i + 1, j + 1});
                union_set(i, j, 0);
                union_set(i, j, 1);
            }
        }
    }

    cout << ans.size() << endl;
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}
