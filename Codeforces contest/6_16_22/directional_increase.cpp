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

        int cnt = 0;
        bool bad = false;
        bool firstZero = false;
        bool allZero = true;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long inp;
            cin >> inp;

            if (inp == 0)
            {
                if (i == 0)
                    firstZero = true;
                continue;
            }

            allZero = false;
            sum += inp;
            if (sum < 0)
                bad = true;
            else if (sum == 0)
            {
                cnt++;
            }
        }

        if ((!bad && sum == 0 && cnt == 1 && !firstZero) ||  allZero)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
