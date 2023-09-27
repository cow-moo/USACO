#include <iostream>
using namespace std;
#define MAXN 100005

long long arr[MAXN];

int solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long prev[] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        arr[i] -= prev[i % 2];
        prev[i % 2] += arr[i];
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int oddNeg = 1, evenNeg = 0, doubleNeg = 0;

    while (doubleNeg + 1 < n && arr[doubleNeg] >= 0 || arr[doubleNeg + 1] >= 0)
    {
        doubleNeg++;
    }

    while (oddNeg < n && oddNeg >= 0 && (oddNeg + 1 < n && ))

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            continue;
        
        if (i + 1 < n && arr[i + 1] > 0)
        {

        }
    }

    return 0;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}