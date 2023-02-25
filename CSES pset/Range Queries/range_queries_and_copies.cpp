#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005
#define SIZE 200005

long long bit[SIZE];
long long arr[MAXN];

long long sum(int i)
{
    i++;
    long long sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, long long delta)
{
    i++;
    while (i <= SIZE)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

struct Query
{
    int type, a, b, index;
};

vector<vector<Query>> queries;
long long ans[MAXN];
int ansIndex = 0;

void recurse(int k, int i)
{
    if (queries[k].size() == i)
        return;

    if (queries[k][i].type == 1)
    {
        int diff = queries[k][i].b - arr[queries[k][i].a];
        add(queries[k][i].a, diff);
        arr[queries[k][i].a] += diff;
        recurse(k, i + 1);
        add(queries[k][i].a, -diff);
        arr[queries[k][i].a] -= diff;
    }
    else if (queries[k][i].type == 2)
    {
        ans[queries[k][i].index] = sum(queries[k][i].b) - sum(queries[k][i].a - 1);
        recurse(k, i + 1);
    }
    else
    {
        recurse(queries[k][i].a, 0);
        recurse(k, i + 1);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        add(i, arr[i]);
    }

    queries = vector<vector<Query>>(1, vector<Query>());
    for (int i = 0; i < q; i++)
    {
        Query query;
        int k;
        cin >> query.type >> k;
        k--;

        if (query.type == 1)
        {
            cin >> query.a >> query.b;
            query.a--;
        }
        else if (query.type == 2)
        {
            cin >> query.a >> query.b;
            query.a--; query.b--;
            query.index = ansIndex++;
        }
        else
        {
            query.a = queries.size();
            queries.push_back(vector<Query>());
        }

        queries[k].push_back(query);
    }

    recurse(0, 0);

    for (int i = 0; i < ansIndex; i++)
    {
        cout << ans[i] << endl;
    }
}