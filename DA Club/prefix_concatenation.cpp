#include <iostream>
using namespace std;
#define MAXN 500005

int prefix[MAXN * 2];

int main()
{
    string s, t;
    cin >> s >> t;
    string concat = s + "$" + t;

    for (int i = 1; i < concat.length(); i++)
    {
        int j = prefix[i - 1];
        while (j > 0 && concat[i] != concat[j])
        {
            j = prefix[j - 1];
        }
        if (concat[i] == concat[j])
        {
            j++;
        }
        prefix[i] = j;
    }

    int ans = 0;
    int i = concat.length() - 1;
    while (i > s.length())
    {
        if (prefix[i] == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        i -= prefix[i];
        ans++;
    }
    cout << ans << endl;
}