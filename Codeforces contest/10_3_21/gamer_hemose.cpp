#include <iostream>
using namespace std;

long long dmg[1050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        long long n, h;
        cin >> n >> h;
        long long maxi = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> dmg[i];
            if (dmg[i] > dmg[maxi]) {
                maxi = i;
            }
        }
        long long maxi2 = -1;
        for (int i = 0; i < n; i++) {
            if (i != maxi && (maxi2 == -1 || dmg[i] > dmg[maxi2]))
                maxi2 = i;
        }

        long long ans = 2 * (h / (dmg[maxi] + dmg[maxi2]) + (h % (dmg[maxi] + dmg[maxi2]) != 0));
        if ((dmg[maxi] + dmg[maxi2]) * ans / 2 - dmg[maxi2] >= h)
            ans--;
        cout << ans << endl;
    }
}
