#include <iostream>
#include <queue>
using namespace std;
#define MAXN 200050

int p[MAXN], childCount[MAXN];
bool removed[MAXN];
pair<long long, long long> ranges[MAXN];

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
            childCount[i] = 0;
            removed[i] = false;
        }

        for (int i = 2; i <= n; i++)
        {
            cin >> p[i];
            childCount[p[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> ranges[i].first >> ranges[i].second;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (childCount[i] == 0)
            {
                q.push(i);
            }
        }

        int ans = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            if (ranges[cur].first <= 0)
                continue;

            long long cura = ranges[cur].second;
            bool done = true;
            while (cur != 0)
            {
                cura = min(cura, ranges[cur].second);

//                if (cura == 0)
//                    break;

                ranges[cur].first -= cura;
                ranges[cur].second -= cura;

                if (ranges[cur].first <= 0)
                {
                    if (!removed[cur] && done)
                    {
                        childCount[p[cur]]--;
                        removed[cur] = true;
                    }
                }
                else if (childCount[cur] == 0)
                {
                    q.push(cur);
                    done = false;
                }

                cur = p[cur];
            }
            ans++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (ranges[i].first > 0)
            {
                while (true)
                {

                }
            }
        }

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
