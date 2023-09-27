#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int one, two, npos;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;

            if (p == 1)
                one = i;
            else if (p == 2)
                two = i;
            else if (p == n)
                npos = i;
        }

        if (npos > two && npos > one)
        {
            cout << npos + 1 << " " << max(one, two) + 1 << "\n";
        }
        else if (npos < two && npos < one)
        {
            cout << npos + 1 << " " << min(one, two) + 1 << "\n";
        }
        else
        {
            cout << "1 1\n";
        }
    }
}