#include <iostream>
using namespace std;

int ans[10005];

int main()
{
    int n;
    cin >> n;

    int l = 1;
    int r = n;

    for (int i = 0; i < n - 1; i++)
    {
        cout << "? " << l << " " << r << endl;
        cout.flush();
        int result1;
        cin >> result1;

        cout << "? " << r << " " << l << endl;
        cout.flush();
        int result2;
        cin >> result2;

        if (result1 < result2)
        {
            ans[r--] = result2;
        }
        else
        {
            ans[l++] = result1;
        }
    }

    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
            cout << n << " ";
        else
            cout << ans[i] << " ";
    }
}
