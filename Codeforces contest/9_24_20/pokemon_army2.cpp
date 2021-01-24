#include <iostream>
using namespace std;

int strengths[300050], contribution[300050], n;

int getContribution(int i)
{
    if (strengths[i] < strengths[i - 1] && strengths[i] < strengths[i + 1])
    {
        return -strengths[i];
    }
    //peak
    else if (strengths[i] > strengths[i - 1] && strengths[i] > strengths[i + 1])
    {
        return strengths[i];
    }
    else
    {
        return 0;
    }
}

int repl(int i, int value)
{
    int change = 0;

    if (i > 1)
    {
        if (strengths[i] > strengths[i - 1] && value < strengths[i - 1])
        {
            if (strengths[i - 1] > strengths[i - 2])
            {
                change += strengths[i - 1];
            }
            else
            {
                change -= strengths[i - 1];
            }
        }
        else if (strengths[i] < strengths[i - 1] && value > strengths[i - 1])
        {

        }
    }
    if (i < n)
    {

    }

    return change;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++)
        {
            cin >> strengths[i];
        }
        strengths[0] = 0;
        strengths[n + 1] = 0;
        contribution[0] = 0;
        contribution[n + 1] = 0;

        long long ans = 0;
        for (int i = 1; i <= n; i++) //O(n)
        {
            //valley
            if (strengths[i] < strengths[i - 1] && strengths[i] < strengths[i + 1])
            {
                ans -= strengths[i];
            }
            //peak
            if (strengths[i] > strengths[i - 1] && strengths[i] > strengths[i + 1])
            {
                ans += strengths[i];
            }
        }

        cout << ans << endl;

        for (int i = 0; i < q; i++) //O(q) * O(repl)
        {
            int l, r, lval, rval;
            cin >> l >> r;
            if (l != r)
            {
                lval = strengths[l];
                rval = strengths[r];
                ans += repl(l, rval);
                ans += repl(r, lval);
            }

            cout << ans << endl;
        }
    }
}

