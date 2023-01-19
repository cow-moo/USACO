#include <iostream>
using namespace std;

int n, ans;
string brackets;

int get_end(int pos)
{
    //if (brackets[pos] == ')')
    //    return pos;
    bool temp = false;
    pos++;
    while (brackets[pos] == '(')
    {
        pos = get_end(pos) + 1;
        temp = true;
    }
    if (temp)
        ans++;
    return pos;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        cin >> n >> brackets;
        brackets = "(" + brackets + ")";
        ans = 0;
        get_end(0);
        cout << ans << endl;
    }
}
