#include <iostream>
using namespace std;

int nums[100050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        long long ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            long long numBit = 0;
            for (int j = 0; j < n; j++)
            {
                if ((nums[j] & (1 << i)) > 0)
                {
                    nums[j] = 0;
                    numBit++;
                }
            }

            ans += numBit * (numBit - 1) / 2;
        }
        cout << ans << endl;
    }
}
