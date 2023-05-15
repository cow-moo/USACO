#include <iostream>
using namespace std;
#define MAXN 300005

int arr[MAXN];

int solve()
{
    int n;
    cin >> n;

    int prev, cur, res = 1, dir = 0;
    cin >> prev;

    for (int i = 1; i < n; i++)
    {
        cin >> cur;
        if (cur > prev && dir != 1)
        {
            res++;
            dir = 1;
        }
        else if (cur < prev && dir != -1)
        {
            res++;
            dir = -1;
        }
        prev = cur;
    }
    return res;
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