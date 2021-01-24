#include <iostream>
#include <set>
#include <queue>
using namespace std;
#define MAXN 100050

int bessie[2 * MAXN];
int elsie[2 * MAXN];
int dist[2 * MAXN];

struct compB
{
    bool operator()(int a, int b) const
    {
        return bessie[a] < bessie[b];
    }
};

struct compE
{
    bool operator()(int a, int b) const
    {
        return elsie[a] < elsie[b];
    }
};

multiset<int, compB> setBessie;
multiset<int, compE> setElsie;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> bessie[i] >> elsie[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (elsie[i] == 0)
            q.push(i), dist[i] = 1;
        else
            setElsie.insert(i);
        if (bessie[n + i] == 0)
            q.push(n + i), dist[n + i] = 1;
        else
            setBessie.insert(n + i);
    }

    while (!q.empty())
    {

    }
}