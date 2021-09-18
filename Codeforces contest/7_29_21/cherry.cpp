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

        long long ans = 0, prev, cur;
        cin >> prev;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> cur;
            ans = max(ans, prev * cur);
            prev = cur;
        }
        cout << ans << endl;
    }
}
