#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long n, d, c, m;
        string s;
        cin >> n >> d >> c >> m >> s;

        int last = n;
        bool good = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
            {
                d--;
                c += m;
            }
            else
            {
                c--;
            }

            if (d < 0 || c < 0)
            {
                last = i;
                break;
            }
        }

        for (int i = last; i < n; i++)
        {
            if (s[i] == 'D')
            {
                good = false;
                break;
            }
        }

        cout << "Case #" << z << ": " << (good ? "YES" : "NO") << endl;
    }
}
