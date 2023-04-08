#include <iostream>
using namespace std;
#define MAXN 1005

bool arr[MAXN][MAXN];

string solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int diff = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            diff += arr[i][j] != arr[n - 1 - i][n - 1 - j];
        }
    }
    diff /= 2;
    //cout << diff << endl;

    return (k >= diff && (n % 2 == 1 || k % 2 == diff % 2)) ? "YES" : "NO";
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