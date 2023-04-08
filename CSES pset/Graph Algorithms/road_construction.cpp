#include <iostream>
using namespace std;
#define MAXN 100005

int parent[MAXN];
int sz[MAXN]; //can also be by rank

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (sz[a] > sz[b])
    {
        swap(a, b);
    }
    parent[a] = b;
    sz[b] += sz[a];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    int num = n, largest = 1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        if (find_set(a) != find_set(b))
        {
            num--;
            union_set(a, b);
            largest = max(largest, sz[find_set(a)]);
        }

        cout << num << " " << largest << endl;
    }
}
