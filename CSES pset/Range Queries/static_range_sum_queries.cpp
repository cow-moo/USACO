#include <iostream>
using namespace std;

long long arr[200050];

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }


    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }
}