#include <iostream>
using namespace std;
#define MAXN 1000010

int z[MAXN];

void z_function(string s)
{
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
}

int prefix[MAXN];

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
    string s;
    cin >> s;
    z_function(s);
    prefix_function(s);

    for (int i = 0; i < s.length(); i++)
    {
        cout << z[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < s.length(); i++)
    {
        cout << prefix[i] << " ";
    }
    cout << "\n";
}