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
        string inp;
        cin >> inp;

        bool allCW = true, allCCW = true;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (inp[i] == '>')
                allCCW = false;
            if (inp[i] == '<')
                allCW = false;

            if (inp[i] == '-')
            {
                ans++;
                if (inp[(i + 1) % n] != '-')
                    ans++;
            }
        }

        if (allCW || allCCW)
            cout << n << endl;
        else
            cout << ans << endl;
    }
}
