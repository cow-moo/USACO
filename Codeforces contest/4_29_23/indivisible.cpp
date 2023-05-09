#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;;

    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n % 2 == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << i * 2 << " " << i * 2 - 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}