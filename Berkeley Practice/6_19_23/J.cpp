#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> num;

bool solve()
{
    string s;
    cin >> s;

    for (int i = 0; i < 7; i++)
    {
        bool bad = false;
        int bag = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (j % 7 == i)
                bag = 0;
            int cur = num[s[j]];
            if (bag & (1 << cur))
            {
                bad = true;
                break;
            }
            bag ^= 1 << cur;
        }
        if (!bad)
            return true;
    }
    return false;
}

int main()
{
    num['J'] = 0;
    num['L'] = 1;
    num['S'] = 2;
    num['Z'] = 3;
    num['I'] = 4;
    num['O'] = 5;
    num['T'] = 6;

    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << '\n';
    }
}