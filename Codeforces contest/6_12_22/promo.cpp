#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200050

long long prices[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }

    sort(prices + 1, prices + n + 1);

    for (int i = 1; i < n; i++)
    {
        prices[i + 1] += prices[i];
    }

//    for (int i = 0; i <= n; i++)
//    {
//        cout << prices[i] << " ";
//    }
//    cout << endl;

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;

        cout << prices[n - x + y] - prices[n - x] << endl;
    }
}
