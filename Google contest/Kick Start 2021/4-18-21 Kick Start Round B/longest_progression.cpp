#include <iostream>
#include <vector>
using namespace std;

int arr[100050];
pair<int, int> diffs[100050];
//diff, length

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            diffs[i] = {0, 0};
        }

        int sz = 0;
        for (int i = 1; i < n; i++)
        {
            int curDiff = arr[i] - arr[i - 1];
            if (sz == 0 || (diffs[sz - 1].first != curDiff))
            {
                diffs[sz++] = {curDiff, 1};
            }
            else
                diffs[sz - 1].second++;
        }

        for (int i = 0; i < sz; i++)
        {
            cout << "{" << diffs[i].first << "," << diffs[i].second << "}" << " ";
        }
        cout << endl;

        int ans = diffs[0].second;

        if (diffs[0].second <= 2 && sz > 1)
        {
            ans = max(ans, diffs[1].second + 1);
            if (diffs[0].second == 1 && diffs[1].second == 1 && sz > 2 && diffs[1].first + diffs[0].first == 2 * diffs[2].first)
            {
                ans = max(ans, diffs[2].second + 2);
            }
        }

        for (int i = 1; i < sz; i++)
        {
            ans = max(ans, diffs[i - 1].second + 1);
            if (diffs[i].second == 1 && i + 1 < sz)
            {
                if (diffs[i + 1].first + diffs[i].first == 2 * diffs[i - 1].first)
                {
                    ans = max(ans, diffs[i - 1].second + 2);
                    if (i + 2 < sz && diffs[i + 1].second == 1 && diffs[i + 2].first == diffs[i - 1].first)
                        ans = max(ans, diffs[i - 1].second + 2 + diffs[i + 2].second);
                }
            }
        }
        if (sz > 1)
            ans = max(ans, diffs[sz - 1].second + 1);
        cout << "Case #" << z << ": " << ans + 1 << endl;
    }
}
