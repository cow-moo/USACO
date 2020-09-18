#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int nums[1005];
bool used[1005];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        vector<int> ans;
        int n;
        cin >> n;

        int maxim = 0;
        int maximIndex;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            if (nums[i] > maxim)
            {
                maxim = nums[i];
                maximIndex = i;
            }
            used[i] = false;
        }
        ans.push_back(maxim);
        used[maximIndex] = true;

        int curGCD = maxim;
        for (int i = 0; i < n - 1; i++)
        {
            maxim = 0;
            for (int j = 0; j < n; j++)
            {
                if (!used[j])
                {
                    //cout << 'j' << j << endl;
                    if (gcd(curGCD, nums[j]) > maxim)
                    {
                        maxim = gcd(curGCD, nums[j]);
                        maximIndex = j;
                    }
                }
            }
            ans.push_back(nums[maximIndex]);
            //cout << "A" << maximIndex << endl;
            used[maximIndex] = true;
            curGCD = maxim;
        }

        for (int i = 0; i < n; i++)
        {
            //cout << used[i] << " ";
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
