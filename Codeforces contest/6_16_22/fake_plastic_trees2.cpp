#include <iostream>
#include <queue>
using namespace std;
#define MAXN 200050

int p[MAXN], childCount[MAXN];
vector<int> children[MAXN];
bool removed[MAXN];
pair<long long, long long> ranges[MAXN];
int ans = 0;

void dfs(int cur)
{
    for (int c : children[cur])
    {
        dfs(c);
    }

    if (ranges[cur].first > 0)
    {
        long long cura = ranges[cur].second;
        while (cur != 0)
        {
            cura = min(cura, ranges[cur].second);

            ranges[cur].first -= cura;
            ranges[cur].second -= cura;

            cur = p[cur];
        }

        ans++;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            children[i].clear();
            removed[i] = false;
        }

        for (int i = 2; i <= n; i++)
        {
            cin >> p[i];
            //childCount[p[i]]++;
            children[p[i]].push_back(i);
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> ranges[i].first >> ranges[i].second;
        }

        ans = 0;
        dfs(1);

        cout << ans << endl;
    }
}
/*
6
1 2 3 3 1
7 7
2 2
7 7
1 3
1 3
10 10
*/
