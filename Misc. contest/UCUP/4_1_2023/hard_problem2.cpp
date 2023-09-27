#include <iostream>
using namespace std;
#define MAXN 100005

long long odd[MAXN], even[MAXN];

int solve()
{
    int n;
    cin >> n;

    int evenSz = (n + 1) / 2;
    int oddSz = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cin >> even[i / 2];
        else
            cin >> odd[i / 2];
    }

    long long prev = 0;
    for (int i = 0; i < evenSz; i++)
    {
        even[i] -= prev;
        prev += even[i];
    }

    prev = 0;
    for (int i = 0; i < evenSz; i++)
    {
        odd[i] -= prev;
        prev += odd[i];
    }

    for (int i = 0; i < evenSz; i++)
    {
        cout << even[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < oddSz; i++)
    {
        cout << odd[i] << " ";
    }
    cout << endl;

    int oddNeg = 0, evenNeg = 0, doubleNeg = 0;

    for (int i = 0; i < n; i++)
    {

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