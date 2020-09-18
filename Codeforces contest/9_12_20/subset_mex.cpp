#include <iostream>
using namespace std;

int cnt[105];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        for (int i = 0; i <= 100; i++)
            cnt[i] = 0;

        int n;
        cin >> n;

        int inp;
        for (int i = 0; i < n; i++)
        {
            cin >> inp;
            cnt[inp]++;
        }

        int mexa = 101, mexb = 101;
        for (int i = 0; i <= 100; i++)
        {
            if (cnt[i] == 1)
            {
                if (mexa == 101)
                {
                    mexa = i;
                }
            }
            else if (cnt[i] == 0)
            {
                if (mexa == 101)
                    mexa = i;
                if (mexb == 101)
                    mexb = i;
                break;
            }
        }

        cout << mexa + mexb << endl;
    }
}
