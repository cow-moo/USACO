#include <iostream>
using namespace std;
#define MAXN 1000005

int prefix[MAXN * 2];

int booth(string s)
{
    s += s;
    //best rotation so far
    int rot = 0;
    for (int r = 1; r < s.length(); r++)
    {
        int l = prefix[r - 1 - rot];
        //int j = prefix[i - 1];
        while (l > 0 && s[l + rot] != s[r])
        {
            if (s[l + rot] > s[r])
            {
                rot = r - l;
            }
            l = prefix[l - 1];
        }
        if (l == 0 && s[l + rot] != s[r])
        {
            if (s[l + rot] > s[r])
            {
                rot = r;
            }
            prefix[r - rot] = 0;
        }
        else
        {
            prefix[r - rot] = l + 1;
        }
    }
    return rot;
}
//l' = l + 1
//l = l' - 1

int main()
{
    string str;
    cin >> str;

    int ans = booth(str);
    cout << str.substr(ans) << str.substr(0, ans) << endl;
}