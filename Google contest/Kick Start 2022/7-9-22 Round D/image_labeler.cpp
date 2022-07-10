#include <iostream>
#include <algorithm>
using namespace std;

long long regions[10050];

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> regions[i];
        }
        sort(regions, regions + n);

        long long ans = 0;
        for (int i = 0; i < m - 1; i++)
        {
            ans += regions[n - 1 - i];
        }
//        double temp = 0;
//        for (int i = 0; i <= n - m; i++)
//        {
//            temp += regions[i];
//        }
//        temp /= (n - m + 1);
        long long med;
        bool half = false;
        if ((n - m + 1) % 2 == 0)
        {
            int temp = (n - m + 1) / 2;
            //cout << "pog" << endl;
            med = (regions[temp] + regions[temp - 1]) / 2;
            if ((regions[temp] + regions[temp - 1]) % 2 == 1)
                half = true;
        }
        else
        {
            int temp = (n - m + 1) / 2;
            med = regions[temp];
        }
        ans += med;
//        long long what = 5.0;
//        cout << what << endl;
//        cout << "asdfaser" << endl;
        cout << "Case #" << z << ": " << ans << (half ? ".5" : "") << endl;
    }
}
