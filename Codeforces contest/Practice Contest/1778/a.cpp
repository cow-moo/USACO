#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool prev = false;
        int res = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;
            sum += inp;
            if (inp == -1)
            {
                if (prev)
                    res = 2;
                else if (res < 2)
                    res = 1;
                prev = true;
            }
            else
                prev = false;
        }
        if (res == 0)
            cout << sum - 4 << endl;
        else if (res == 1)
            cout << sum << endl;
        else
            cout << sum + 4 << endl;
    }
}