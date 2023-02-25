#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100050

int arr[MAXN];
int sorted[MAXN];

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
            sorted[i] = arr[i];
        }

        sort(sorted, sorted + n);

        cout << "Case #" << z << ":";

        for (int i = 0; i < n; i++)
        {
            int *upper = upper_bound(sorted, sorted + n, 2 * arr[i]) - 1;
            //cout << " " << arr[i] << ":" << (*upper) << endl;
            if ((*upper) == arr[i])
            {
                if (upper != sorted)
                    upper--;
                else
                {
                    cout << " " << -1;
                    continue;
                }
            }
            cout << " " << *upper;
        }
        cout << endl;
    }
}
