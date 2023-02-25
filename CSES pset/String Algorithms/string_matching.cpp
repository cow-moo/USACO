#include <iostream>
using namespace std;
#define MAXN 1000005

int prefix[MAXN * 2];

void prefix_function(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j])
            j = prefix[j - 1];
        j += s[i] == s[j];
        prefix[i] = j;
    }
}

int main()
{
    string s, t;
    cin >> s >> t;

    string str = t + "$" + s;
    prefix_function(str);

    int ans = 0;
    for (int i = t.length() + 1; i < str.length(); i++)
    {
        if (prefix[i] == t.length())
            ans++;
    }
    cout << ans << endl;
}