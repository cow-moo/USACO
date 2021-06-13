#include <iostream>
using namespace std;

int n, x;
int heights[100050];

int findMaxStacks(int minHeight, bool print)
{
    int stackCount = 0;
    int curHeight = 0;

    for (int i = 0; i < n; i++)
    {
        curHeight += heights[i];

        if (print)
            cout << stackCount + 1 << " ";

        if (curHeight >= minHeight)
        {
            stackCount++;
            curHeight = 0;
        }
    }
    if (print)
        cout << endl;

    return stackCount;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int m;
        cin >> n >> m >> x;

        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        int l = 0, r = 1000000000, mid;
        bool found = false;
        int minHeight;

        while (l < r)
        {
            //0 => big
            //10000 => small
            mid = r - (r - l) / 2;
            int maxStacks = findMaxStacks(mid, false);
            cout << mid << ": " << maxStacks << endl;
            if (maxStacks > m)
            {
                l = mid + 1;
            }
            else if (maxStacks < m)
            {
                r = mid - 1;
            }
            else
            {
                found = true;
            }
        }

        if (found)
        {
            cout << "YES" << endl;
            findMaxStacks(mid, true);
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
