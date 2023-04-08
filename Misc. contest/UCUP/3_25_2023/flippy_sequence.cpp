#include <iostream>
using namespace std;

long long solve()
{
    long long n;
    string s, t;
    cin >> n >> s >> t;

    int cnt1 = 0, cnt2 = 0;
    int start1, start2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            if (cnt1 >= 0)
            {
                cnt1++;
                if (cnt1 == 0)
                    start1 = i;
            }
            else if (cnt2 >= 0)
            {
                cnt2++;
                if (cnt2 == 0)
                    start2 = 0;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (cnt1 > 0)
            {
                cnt1 = -cnt1;
            }
            else if (cnt2 > 0)
            {
                cnt2 = -cnt2;
            }
        }
    }
    cnt1 = -cnt1;
    cnt2 = -cnt2;

    if (cnt2 == 0 && cnt1 == 0)
    {
        return n * (n + 1) / 2;
    }
    else if (cnt2 == 0)
    {
        //return (start1 + (n - start1 - cnt1) + cnt1 - 1) * 2;
        return (n - 1) * 2;
    }
    else
    {
        return 6;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        cout << solve() << endl;
    }
}