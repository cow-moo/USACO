#include <iostream>
using namespace std;

string solve()
{
    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res ^= x;
    }
    return res == 0 ? "second" : "first";
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
// 11
//101