#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        int ans;
        cin >> ans;
        for (int i = 1; i < n; i++)
        {
            int inp;
            cin >> inp;
            ans &= inp;
        }

        cout << ans << endl;
    }
}
