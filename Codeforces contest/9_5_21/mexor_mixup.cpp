#include <iostream>
#include <algorithm>
using namespace std;

int ans[50050];
pair<pair<int, int>, int> q[50050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int a, b;
        cin >> a >> b;

        q[z] = {{a, b}, z};
    }

    sort(q, q + t);

    int curxor = 0;
    int lastxor = 0;
    for (int i = 0; i < t; i++)
    {
        while (lastxor < q[i].first.first - 1)
        {
            curxor ^= ++lastxor;
        }
        int temp = curxor ^ q[i].first.second;
        if (temp == 0)
        {
            ans[q[i].second] = q[i].first.first;
        }
        else if (temp != q[i].first.first)
        {
            ans[q[i].second] = q[i].first.first + 1;
        }
        else
        {
            ans[q[i].second] = q[i].first.first + 2;
        }
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
}
