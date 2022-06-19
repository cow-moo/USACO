#include <iostream>
#include <algorithm>
using namespace std;

int arr[200050];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            ans++;
    }

    cout << ans << endl;
}
