#include <iostream>
using namespace std;

int arr[105];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, x;
        cin >> n >> x;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if (sum == x)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == x)
            {
                swap(arr[i], arr[i + 1]);
            }
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
