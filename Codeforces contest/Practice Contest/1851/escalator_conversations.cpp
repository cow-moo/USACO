#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k, h;
        cin >> n >> m >> k >> h;
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cur;
            cin >> cur;

            if ((cur - h) % k == 0 && abs(cur - h) / k < m && cur != h)
                ans++;
        }
        cout << ans << endl;
    }
}
//height 15
//cur 12