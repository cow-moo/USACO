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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    prefix_function(s);

    for (int i = prefix[s.length() - 1]; i > 0; i = prefix[i - 1])
    {
        cout << s.length() - i << " ";
    }
    
    cout << s.length() << endl;
}