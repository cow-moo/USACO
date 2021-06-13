#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long g;
        cin >> g;

        int ans = 0;
        //vector<int> factors;
        for (long long i = 1; i * i <= 2 * g; i++)
        {
            if ((2 * g) % i == 0)
            {
                long long temp = 2 * g / i - i + 1;
                if (temp % 2 == 0)
                {
                    ans++;
                }
            }
        }
        cout << "Case #" << z << ": " << ans << endl;
    }
}
