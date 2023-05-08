#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 200005

int ans[MAXN];
vector<pair<pair<int, bool>, int>> times;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        times.push_back({{a, 0}, i});
        times.push_back({{b, 1}, i});
    }
    sort(times.begin(), times.end());

    int rooms = 0;
    queue<int> available;
    for (auto p : times)
    {
        if (p.first.second)
        {
            available.push(ans[p.second]);
        }
        else
        {
            if (available.empty())
            {
                ans[p.second] = rooms++;
            }
            else
            {
                ans[p.second] = available.front();
                available.pop();
            }
        }
    }

    cout << rooms << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}