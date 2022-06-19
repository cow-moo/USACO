#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        string str;
        cin >> n >> str;

        bool upper, lower, digit, special;
        upper = lower = digit = special = false;

        for (int i = 0; i < n; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                upper = true;
            else if (str[i] >= 'a' && str[i] <= 'z')
                lower = true;
            else if (str[i] >= '0' && str[i] <= '9')
                digit = true;
            else if (str[i] == '#' || str[i] == '@' || str[i] == '*' || str[i] == '&')
                special = true;
        }

        if (!upper)
            str += 'A';
        if (!lower)
            str += 'a';
        if (!digit)
            str += '0';
        if (!special)
            str += '#';

        while (str.length() < 7)
            str += 'a';

        cout << "Case #" << z << ": " << str << endl;
    }
}
