#include <iostream>
using namespace std;

int nums[105][3];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> nums[i][j];
            }
        }

        int prev = nums[0][0];
        cout << prev << " ";
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (nums[i][j] != prev)
                {
                    cout << nums[i][j] << " ";
                    prev = nums[i][j];
                    break;
                }
            }
        }

        for (int j = 0; j < 3; j++)
        {
            if (nums[n - 1][j] != prev && nums[n - 1][j] != nums[0][0])
            {
                cout << nums[n - 1][j] << endl;
                break;
            }
        }
    }
}
