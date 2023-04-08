#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (i + 1 >= arr[i])
        {
            cout << i + 1 << endl;
            break;
        }
    }
}
