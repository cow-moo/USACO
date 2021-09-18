#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;

int main()
{
    int t;
    cin >> t;

    cout << fixed;
    cout << setprecision(7);
    for (int z = 1; z <= t; z++)
    {
        long long n;
        cin >> n;

        double ans = 0;

        if (n <= 1000000)
        {
            for (long long i = 1; i <= n; i++)
            {
                //cout << "?";
                ans += 1.0 / (double) i;
            }
        }
        else
        {
            ans = log(n) + 0.577215665;
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
