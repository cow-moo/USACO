#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        string a, b;
        cin >> n >> k >> a >> b;

        long long cnt = 0;
        map<char, int> num;
        for (int i = 0; i < n; i++)
        {
            if (num.count(a[i]) == 0)
            {
                num[a[i]] = cnt++;
            }
        }

        if (num.size() <= k)
        {
            cout << (n * (n + 1) / 2) << endl;
            continue;
        }

        //for (auto p : num)
        //    cout << p.first << " " << p.second << endl;
        long long ans = 0;
        for (int bits = 0; bits < (1 << num.size()); bits++)
        {
            if (__builtin_popcount(bits) != k)
                continue;

            long long cur = 0, res = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[i] || bits & (1 << num[a[i]]))
                {
                    cur++;
                }
                else
                {
                    res += cur * (cur + 1) / 2;
                    cur = 0;
                }
            }
            res += cur * (cur + 1) / 2;
            ans = max(res, ans);
        }
        cout << ans << endl;
    }
}