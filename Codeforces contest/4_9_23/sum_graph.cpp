#include <iostream>
using namespace std;
#define MAXN 1005

int p[MAXN];

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int res;

        cout << "+ " << n + 1 << endl;
        cout.flush();
        cin >> res;
        if (res == -2)
            return 0;

        cout << "+ " << n + 2 << endl;
        cout.flush();
        cin >> res;
        if (res == -2)
            return 0;

        int end, endDist = 0;
        for (int i = 2; i <= n; i++)
        {
            cout << "? 1 " << i << endl;
            cout.flush();
            
            int r;
            cin >> r;
            if (r == -2)
                return 0;
            if (r > endDist)
            {
                end = i;
                endDist = r;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (end == i)
                continue;
            
            cout << "? " << end << " " << i << endl;
            cout.flush();

            cin >> p[i];
            if (p[i] == -2)
                return 0;
        }
        p[end] = 0;

        cout << "! ";
        for (int j = 0; j < 2; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (p[i] % 2 == 0)
                {
                    cout << p[i] / 2 + 1 << " ";
                }
                else
                {
                    cout << n - p[i] / 2 << " ";
                }
                p[i] = n - 1 - p[i];
            }
        }
        cout.flush();
        cin >> res;
        if (res == -2)
            return 0;
    }
}