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

        bool decreasing = true;
        int prev;
        cin >> prev;
        for (int i = 1; i < n; i++)
        {
            int inp;
            cin >> inp;
            if (inp >= prev)
            {
                decreasing = false;
            }
            prev = inp;
        }

        cout << (decreasing ? "NO" : "YES") << endl;
    }
}
