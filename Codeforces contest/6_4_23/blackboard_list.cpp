#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ans;
        cin >> ans;
        for (int i = 1; i < n; i++)
        {
            int a;
            cin >> a;

            if (ans >= 0 && (a < 0 || a > ans))
                ans = a;
        }
        cout << ans << endl;
    }
}