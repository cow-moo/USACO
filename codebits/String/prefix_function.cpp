#include <iostream>
using namespace std;
#define MAXN 500005

//prefix[i] is longest proper prefix = suffix for s[0..i]
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

    prefix_function(s);

    for (int i = 0; i < s.length(); i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < s.length(); i++)
        cout << s[i] << " ";
    cout << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << prefix[i] << " ";
    }
    cout << endl;
}

//aabab