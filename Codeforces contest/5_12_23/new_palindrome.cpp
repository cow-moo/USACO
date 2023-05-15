#include <iostream>
using namespace std;

bool solve()
{
    string str;
    cin >> str;

    for (int i = 1; i < str.length() / 2; i++)
    {
        if (str[i] != str[i - 1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << (solve() ? "YES" : "NO") << endl;
    }
}