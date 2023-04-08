#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005

pair<int, int> arr[MAXN];

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr, arr + n);

    int l = 0, r = n - 1;
    while (l < r)
    {
        if (arr[l].first + arr[r].first > x)
            r--;
        else if (arr[l].first + arr[r].first < x)
            l++;
        else
        {
            cout << arr[l].second << " " << arr[r].second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
