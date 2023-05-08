#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 200005

pair<int, int> movies[MAXN];
multiset<int> active;

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies, movies + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!active.empty() && movies[i].first >= *active.begin())
        {
            active.erase(active.begin());
            ans++;
        }

        if (active.size() == k)
        {
            if (movies[i].second < *active.rbegin())
            {
                active.erase(--active.end());
                active.insert(movies[i].second);
            }
        }
        else
        {
            active.insert(movies[i].second);
        }
    }

    cout << ans + active.size() << endl;
}