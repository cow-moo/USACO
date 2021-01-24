#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> cows[205];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows, cows + n);
    int ans = n + 1;

    for (int i = 0; i < n; i++)
    {
        set<int> cur;
        for (int j = i + 1; j < n; j++)
        {
            int width = cows[j].first - cows[i].first;
            auto lower = cur.lower_bound(max(cows[i].second, cows[j].second) - width);
            auto upper = cur.lower_bound(*lower + width);
            while (upper != cur.end() && min(cows[i].second, cows[j].second) + width >= *upper)
            {
                int nextLower = *(++lower) + 1;
                int nextUpper = *(++upper) - width;
                if (nextLower > nextUpper)
                {
                    nextLower--;
                }
                if (nextUpper > nextLower)
                {
                    nextUpper--;
                }
                ans++;
            }


            //*lower <= y <= *lower + width included
        }
    }
}