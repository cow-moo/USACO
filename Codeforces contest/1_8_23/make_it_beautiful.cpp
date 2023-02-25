#include <iostream>
using namespace std;

int arr[55];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, sum = 0;
        bool bad = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (sum == arr[i])
            {
                sum += arr[i];
                swap(arr[i], arr[i - 1]);
            }
            else
                sum += arr[i];
        }
        if (arr[0] == arr[1])
        {
            bad = true;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] != arr[0])
                {
                    swap(arr[i], arr[0]);
                    bad = false;
                    break;
                }
            }
        }

        if (!bad)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
//1 1 2 3
//3 2 1 1
