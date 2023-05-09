#include <iostream>
using namespace std;

int solve()
{
    int n, k;
    cin >> n >> k;

    string me;
    cin >> me;

    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j <= k; j++)
        {
            if (j == k)
            {
                cnt++;
            }
            else if (s[j] != me[j])
            {
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}