#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        string str;
        cin >> n >> str;

        long long ans = n;
        for (int i = 1; i < n; i++)
        {
            if (str[i] != str[i - 1])
                ans += i;
        }

        cout << ans << endl;
    }
}
