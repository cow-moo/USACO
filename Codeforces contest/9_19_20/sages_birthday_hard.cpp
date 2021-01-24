#include <iostream>
#include <algorithm>
using namespace std;

int prices[100050];
int newOrder[100050];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    sort(prices, prices + n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            newOrder[i] = prices[n / 2 + i / 2];
        }
        else
        {
            newOrder[i] = prices[(i / 2)];
        }
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i += 2)
    {
        if (newOrder[i] < newOrder[i - 1] && newOrder[i] < newOrder[i + 1])
            ans++;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << newOrder[i] << " ";
    }
}

