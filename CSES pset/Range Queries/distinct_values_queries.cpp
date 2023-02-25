#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define MAXN 200050
#define SIZE 200050

int bit[SIZE];

int sum(int i)
{
    i++;
    int sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}

void add(int i, int delta)
{
    i++;
    while (i <= SIZE)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

int arr[MAXN];
pair<pair<int, int>, int> queries[MAXN];
unordered_map<int, int> cur;
int ans[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].first.first--; queries[i].first.second--;
        queries[i].second = i;
    }

    sort(queries, queries + q);
    int head = q - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (cur.count(arr[i]) == 1)
        {
            add(cur[arr[i]], -1);
        }
        cur[arr[i]] = i;
        add(i, 1);

        while (head >= 0 && queries[head].first.first == i)
        {
            ans[queries[head].second] = sum(queries[head].first.second);
            head--;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}