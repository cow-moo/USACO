#include <iostream>
#include <set>
using namespace std;
#define MAXN 200005

set<int> pos;

int main()
{
    int n, q;
    string s;
    cin >> n >> q >> s;

    if (n % 2 == 1)
    {
        for (int i = 0; i < q; i++)
        {
            int a;
            cin >> a;
            cout << "NO\n";
        }
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            pos.insert(i);
    }

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        a--;
        if (a > 0 && s[a - 1] == s[a])
            pos.erase(a - 1);
        else if (a > 0)
            pos.insert(a - 1);
        if (a < n - 1 && s[a] == s[a + 1])
            pos.erase(a);
        else if (a < n - 1)
            pos.insert(a);
        s[a] = s[a] == '(' ? ')' : '(';
        // cout << s;
        // for (auto p : pos)
        //     cout << " " << p;
        // cout << "\n";

        if (!pos.empty())
            cout << ((s[0] == '(' && s[n - 1] == ')' && s[*pos.begin()] == '(' && s[*pos.rbegin()] == ')') ? "YES" : "NO") << "\n";
        else
            cout << (s[0] == '(' ? "YES" : "NO") << "\n";
    }
}