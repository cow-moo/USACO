#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cur = 1;
        cout << "Case #" << z << ": 1";
        for (int i = 1; i < n; i++)
        {
            if (s[i] > s[i - 1])
                cur++;
            else
                cur = 1;
            cout << " " << cur;
        }
        cout << endl;
    }
}
