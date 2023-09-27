#include <iostream>
using namespace std;
#define MAXN 100005

int pos[MAXN];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, d;
        cin >> n >> m >> d;

        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            pos[p] = i;
        }

        int ans = 1000000;
        int prev;
        cin >> prev;
        for (int i = 1; i < m; i++)
        {
            int cur;
            cin >> cur;
            //cout << pos[cur] << " " << pos[prev] << endl;
            ans = min(ans, pos[cur] - pos[prev]);
            if (d + 1 < n)
                ans = min(ans, d + 1 - (pos[cur] - pos[prev]));
            prev = cur;
        }
        cout << max(ans, 0) << endl;
    }
}
/*
1
6 2 6
6 3 2 4 5 1
6 1
1
*/