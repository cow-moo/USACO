#include <iostream>
#include <algorithm>
using namespace std;

int arr[100050];
int sorted[100050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, x;
        cin >> n >> x;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sorted[i] = arr[i];
        }

        if (x <= n / 2)
        {
            cout << "YES" << endl;
            continue;
        }
        sort(sorted, sorted + n);

        bool bad = false;
        for (int i = n - x; i < x; i++) {
            if (sorted[i] != arr[i])
            {
                bad = true;
                break;
            }
        }
        if (bad)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
