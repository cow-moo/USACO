#include <iostream>
using namespace std;
#define INF 100000000

int closest[500050];

int main()
{
    int t;
    cin>> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        string str;
        cin >> n >> str;

        int last = -INF;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
                last = i;
            closest[i] = i - last;
        }

        last = INF;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (str[i] == '1')
                last = i;
            ans += min(closest[i], last - i);
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
