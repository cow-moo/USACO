#include <iostream>
using namespace std;
#define MAXN 100000

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

}
