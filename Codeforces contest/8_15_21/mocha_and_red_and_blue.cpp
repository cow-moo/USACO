#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        string s;
        cin >> n >> s;

        for (int i = 0; i < n + 1; i++)
        {
            if (i == n)
            {
                s[0] = 'R';
            }
            else if (s[i] != '?')
            {
                if (i % 2 == 0)
                {
                    s[0] = s[i];
                }
                else
                {
                    s[0] = s[i] == 'R' ? 'B' : 'R';
                }
                break;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '?')
                s[i] = s[i - 1] == 'R' ? 'B' : 'R';
        }

        cout << s << endl;
    }
}
