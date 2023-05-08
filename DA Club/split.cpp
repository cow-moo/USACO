#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s[0] == '1')
    {
        cout << "No" << endl;
        return 0;
    }

    bool cols[7];

    cols[0] = s[6] == '1';
    cols[1] = s[3] == '1';
    cols[2] = s[2] == '1' || s[7] == '1';
    cols[3] = s[0] == '1' || s[4] == '1';
    cols[4] = s[2] == '1' || s[8] == '1';
    cols[5] = s[5] == '1';
    cols[6] = s[9] == '1';

    bool oneZero = false;
    for (int i = 1; i < 7; i++)
    {
        if (cols[i - 1] && !cols[i])
            oneZero = true;

        if (oneZero && cols[i])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}