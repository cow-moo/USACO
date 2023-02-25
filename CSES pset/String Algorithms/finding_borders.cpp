#include <iostream>
using namespace std;
#define MAXN 1000005

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

void recurse(int cur)
{
    if (cur < 1)
        return;
    recurse(prefix[cur - 1]);
    cout << cur << " ";
}

int main()
{
    string str;
    cin >> str;

    prefix_function(str);

    recurse(prefix[str.length() - 1]);
    cout << endl;
}