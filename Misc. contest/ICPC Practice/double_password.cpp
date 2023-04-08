#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 1;
    for (int i = 0; i < 4; i++)
    {
        if (s1[i] != s2[i])
            ans *= 2;
    }
    cout << ans << endl;
}
