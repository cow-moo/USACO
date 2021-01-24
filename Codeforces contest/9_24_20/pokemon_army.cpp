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
    //check if left is peak
//    if (index > 1)
//    {
//        change -= getContribution(index - 1);
//    }
//    //check if right is peak
//    if (index < n)
//    {
//        change -= getContribution(index + 1);
//    }
//    change -= getContribution(index);

    change -= contribution[i - 1];
    change -= contribution[i];
    change -= contribution[i + 1];

    strengths[i] = value;

    if (i > 1)
        contribution[i - 1] = getContribution(i - 1);
    contribution[i] = getContribution(i);
    if (i < n)
        contribution[i + 1] = getContribution(i + 1);

    change += contribution[i - 1];
    change += contribution[i];
    change += contribution[i + 1];
//    if (index > 1)
//    {
//        change += getContribution(index - 1);
//    }
//    //check if right is peak
//    if (index < n)
//    {
//        change += getContribution(index + 1);
//    }
//    change += getContribution(index);

    return change;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
//            if (strengths[i] < strengths[i - 1] && strengths[i] < strengths[i + 1])
//            {
//                ans -= strengths[i];
//            }
//            //peak
//            if (strengths[i] > strengths[i - 1] && strengths[i] > strengths[i + 1])
//            {
//                ans += strengths[i];
//            }
            contribution[i] = getContribution(i);
            ans += contribution[i];
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
